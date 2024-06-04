#include "MyPhysicsWorld.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyPhysicsWorld::MyPhysicsWorld() {}
//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void MyPhysicsWorld::update(float time) {
    this->updateParticleList();
    for (list<MyParticle*>::iterator particle = this->particles.begin();
         particle != this->particles.end();
         particle++) {
        (*particle)->update(time);
    }
}
void MyPhysicsWorld::addParticle(MyParticle* particleToAdd) {
    this->particles.push_back(particleToAdd);
}
void MyPhysicsWorld::updateParticleList() {
    this->particles.remove_if([](MyParticle* particle) { return particle->getIsDestroyed(); });
}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
