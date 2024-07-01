#include "MyPhysicsWorld.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyPhysicsWorld::MyPhysicsWorld(list<My3DModel*>* renderingList)
    : renderingList(renderingList),
      updateCount(0),
      forceRegistry(MyForceRegistry()),
      gravityGenerator(MyGravityGenerator()),
      contactResolver(MyContactResolver(20)) {}

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
    if (this->contacts.size() > 0) {
        this->contacts = contactResolver.resolveContacts(this->contacts, time);
    }
}
void MyPhysicsWorld::addParticle(MyParticle* particleToAdd) {
    this->particles.push_back(particleToAdd);
    if (particleToAdd->getModel3D() != NULL)
        this->renderingList->push_back(particleToAdd->getModel3D());
}
void MyPhysicsWorld::addParticleContact(MyParticle* particle0,
                                        MyParticle* particle1,
                                        double restitution) {
    MyParticle* particles[2] = {particle0, particle1};
    MyVector3 contactNormal  = particle0->getPosition() - particle1->getPosition();
    this->contacts.push_back(
        new MyParticleContact(particles, restitution, contactNormal.getNormalized()));
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

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
list<My3DModel*>* MyPhysicsWorld::getRenderingList() { return this->renderingList; }
vector<MyParticle*> MyPhysicsWorld::getParticleListAsVector() {
    vector<MyParticle*> particleListAsVector{begin(this->particles), end(this->particles)};
    return particleListAsVector;
}
MyForceRegistry* MyPhysicsWorld::getForceRegistry() { return &this->forceRegistry; }
