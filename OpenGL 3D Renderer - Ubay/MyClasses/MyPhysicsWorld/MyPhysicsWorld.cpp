#include "MyPhysicsWorld.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyPhysicsWorld::MyPhysicsWorld(list<My3DModel*>* renderingList)
    : renderingList(renderingList),
      particles({}),
      particleLinks({}),
      lines({}),
      contacts({}),
      updateCount(0),
      forceRegistry(MyForceRegistry()),
      gravityGenerator(MyGravityGenerator()),
      contactResolver(MyContactResolver(MAX_CONTACT_RESOLUTIONS_PER_FRAME)) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void MyPhysicsWorld::update(double time) {
    this->updateParticleList();
    this->forceRegistry.updateForces(time);
    this->updateCount++;
    for (MyParticle* particle : this->particles) {
        particle->update(time, updateCount);
        this->updateGravity(particle);
    }
    this->generateContacts();
    if (this->contacts.size() > 0) {
        contactResolver.resolveContacts(this->contacts, time);
    }
}
void MyPhysicsWorld::addParticle(MyParticle* particleToAdd) {
    this->particles.push_back(particleToAdd);
    if (particleToAdd->getModel3D() != NULL)
        this->renderingList->push_back(particleToAdd->getModel3D());
}

void MyPhysicsWorld::addParticles(vector<MyParticle*> particlesToAdd) {
    for (MyParticle* particleToAdd : particlesToAdd) {
        this->addParticle(particleToAdd);
    }
}

void MyPhysicsWorld::addParticleContact(MyParticle* particleA,
                                        MyParticle* particleB,
                                        double restitution,
                                        double depth,
                                        MyVector3 direction) {
    this->contacts.push_back(
        new MyParticleContact(particleA, particleB, restitution, depth, direction));
}
MyAnchoredSpring* MyPhysicsWorld::addSpring(MyParticle* particle,
                                            MyVector3 anchorPoint,
                                            double springConstant,
                                            double restLength) {
    MyAnchoredSpring* anchoredSpring =
        new MyAnchoredSpring(anchorPoint, springConstant, restLength);

    this->forceRegistry.add(particle, anchoredSpring);
    if (SHOW_RENDER_LINES) this->addLine(new MyParticle(anchorPoint), particle);

    return anchoredSpring;
}
vector<MyParticleSpring*> MyPhysicsWorld::addSpring(MyParticle* particleA,
                                                    MyParticle* particleB,
                                                    double springConstant,
                                                    double restLength) {
    MyParticleSpring* particleSpringA = new MyParticleSpring(particleB, springConstant, restLength);
    MyParticleSpring* particleSpringB = new MyParticleSpring(particleA, springConstant, restLength);

    this->forceRegistry.add(particleA, particleSpringA);
    this->forceRegistry.add(particleB, particleSpringB);
    if (SHOW_RENDER_LINES) this->addLine(particleA, particleB);

    return {particleSpringA, particleSpringB};
}
MyRod* MyPhysicsWorld::addRod(MyParticle* particleA, MyParticle* particleB, double length) {
    MyRod* newRod = new MyRod(particleA, particleB, length);
    this->particleLinks.push_back(newRod);
    if (SHOW_RENDER_LINES) this->addLine(particleA, particleB);
    return newRod;
}

void MyPhysicsWorld::generateContacts() {
    this->contacts.clear();

    this->getOverlaps();

    for (MyParticleLink* link : this->particleLinks) {
        MyParticleContact* contact = link->getContact();
        if (contact != nullptr) this->contacts.push_back(contact);
    }
}
void MyPhysicsWorld::updateParticleList() {
    this->particles.remove_if([](MyParticle* particle) { return particle->getIsDestroyed(); });
}
void MyPhysicsWorld::updateGravity(MyParticle* particle) {
    if (particle->getUsesGravity()) {
        this->forceRegistry.add(particle, &this->gravityGenerator);
    } else {
        this->forceRegistry.remove(particle, &this->gravityGenerator);
    }
}
void MyPhysicsWorld::getOverlaps() {
    for (int i = 0; i < this->particles.size() - 1; i++) {
        list<MyParticle*>::iterator particle = next(this->particles.begin(), i);
        for (int h = i + 1; h < this->particles.size(); h++) {
            list<MyParticle*>::iterator otherParticle = next(this->particles.begin(), h);

            MyVector3 squareMagnitudeVector =
                (*particle)->getPosition() - (*otherParticle)->getPosition();
            double squareMagnitude = squareMagnitudeVector.getSquareMagnitude();
            double squareRadius    = ((*particle)->getRadius() + (*otherParticle)->getRadius());
            squareRadius           = squareRadius * squareRadius;
            if (squareMagnitude <= squareRadius) {
                cout << "OVERLAP" << endl;
                this->addParticleContact(
                    (*particle),
                    (*otherParticle),
                    fmin((*particle)->getRestitution(), (*otherParticle)->getRestitution()),
                    sqrt(squareRadius - squareMagnitude),
                    squareMagnitudeVector.getNormalized());
            }
        }
    }
}
void MyPhysicsWorld::addAnchoredRope(MyAnchoredRope* rope) {
    if (rope->getSegmentCount() == 0) {
        cout << "Rope length has to be a positive integer." << endl;
    } else {
        for (int i = 0; i < rope->getSegmentCount(); i++) {
            MyRenderParticle* newParticle = new MyRenderParticle(rope->getModel(), rope->getTint());
            newParticle->setUsesGravity(rope->getUsesGravity());
            if (i == 0)
                newParticle->setPosition(
                    MyVector3(rope->getAnchorPoint().x,
                              rope->getAnchorPoint().y + rope->getSegmentRestLength(),
                              rope->getAnchorPoint().z));
            else
                newParticle->setPosition(MyVector3(
                    rope->getParticles()[i - 1]->getPosition().x,
                    rope->getParticles()[i - 1]->getPosition().y + rope->getSegmentRestLength(),
                    rope->getParticles()[i - 1]->getPosition().z));
            this->particles.push_back(newParticle);
            rope->addParticle(newParticle);
            if (i > 0) {
                rope->addSegments(this->addSpring(newParticle,
                                                  rope->getParticles()[i - 1],
                                                  rope->getSpringConstant(),
                                                  rope->getSegmentRestLength()));
            } else {
                rope->setHeadSegment(this->addSpring(newParticle,
                                                     rope->getAnchorPoint(),
                                                     rope->getSpringConstant(),
                                                     rope->getSegmentRestLength()));
            }
        }
    }
}
void MyPhysicsWorld::addAnchoredChain(MyAnchoredChain* chain) {
    if (chain->getSegmentCount() == 0) {
        cout << "Chain length has to be a positive integer." << endl;
    } else {
        for (int i = 0; i < chain->getSegmentCount(); i++) {
            MyRenderParticle* newParticle =
                new MyRenderParticle(chain->getModel(), chain->getTint());
            newParticle->setUsesGravity(chain->getUsesGravity());
            if (i == 0)
                newParticle->setPosition(
                    MyVector3(chain->getAnchorPoint().x,
                              chain->getAnchorPoint().y + chain->getSegmentLength(),
                              chain->getAnchorPoint().z));
            else
                newParticle->setPosition(MyVector3(
                    chain->getParticles()[i - 1]->getPosition().x,
                    chain->getParticles()[i - 1]->getPosition().y + chain->getSegmentLength(),
                    chain->getParticles()[i - 1]->getPosition().z));
            this->particles.push_back(newParticle);
            chain->addParticle(newParticle);
            if (i > 0) {
                chain->addSegment(this->addRod(
                    newParticle, chain->getParticles()[i - 1], chain->getSegmentLength()));
            } else {
                chain->setHeadSegment(
                    this->addSpring(newParticle, chain->getAnchorPoint(), 1.0f, 1.0f));
            }
        }
    }
}

void MyPhysicsWorld::addLine(MyParticle* particleA, MyParticle* particleB) {
    this->lines.push_back(new MyParticleLine(particleA, particleB));
}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
list<My3DModel*>* MyPhysicsWorld::getRenderingList() { return this->renderingList; }
vector<MyParticle*> MyPhysicsWorld::getParticleListAsVector() {
    vector<MyParticle*> particleListAsVector{begin(this->particles), end(this->particles)};
    return particleListAsVector;
}
MyForceRegistry* MyPhysicsWorld::getForceRegistry() { return &this->forceRegistry; }
