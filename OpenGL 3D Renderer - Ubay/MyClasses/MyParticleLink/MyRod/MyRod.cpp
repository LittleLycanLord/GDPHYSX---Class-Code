#include "MyRod.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyRod::MyRod(MyParticle* particleA, MyParticle* particleB, double length)
    : MyParticleLink(particleA, particleB),
      length(length),
      restitution(0.0f) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
MyParticleContact* MyRod::getContact() {
    if (this->getCurrentLength() == this->length) return nullptr;
    MyVector3 direction =
        MyVector3(this->particleA->getPosition() - this->particleB->getPosition()).getNormalized();

    MyParticleContact* contact =
        new MyParticleContact(this->particleA, this->particleB, this->restitution, direction);

    if (this->getCurrentLength() > this->length) {
        contact->setContactNormal(direction);
        contact->setDepth(this->getCurrentLength() - this->length);
    } else {
        contact->setContactNormal(direction * -1);
        contact->setDepth(this->length - this->getCurrentLength());
    }
    contact->setRestitition(this->restitution);
    return contact;
}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
