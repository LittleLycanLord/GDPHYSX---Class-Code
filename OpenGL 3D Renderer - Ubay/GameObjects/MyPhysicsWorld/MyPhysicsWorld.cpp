#include "MyPhysicsWorld.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyPhysicsWorld::MyPhysicsWorld() : updateCount(0) {}
//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void MyPhysicsWorld::update(float time) {
    this->updateParticleList();
    this->updateCount++;
    for (list<MyParticle*>::iterator particle = this->particles.begin();
         particle != this->particles.end();
         particle++) {
        (*particle)->update(time, updateCount);
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
