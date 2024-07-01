#include "MyParticleContact.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyParticleContact::MyParticleContact(MyParticle* particles[],
                                     double restitition,
                                     MyVector3 contactNormal)
    : restitition(restitition),
      contactNormal(contactNormal) {
    this->particles[0] = particles[0];
    this->particles[1] = particles[1];
}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
double MyParticleContact::calculateSeparatingSpeed() {
    MyVector3 velocity = this->particles[0]->getVelocity();
    if (particles[1]) velocity -= particles[1]->getVelocity();
    return velocity.DotMultiplication(this->contactNormal);
}
void MyParticleContact::resolveVelocity(double time) {
    double separatingSpeed = calculateSeparatingSpeed();

    if (separatingSpeed > 0) return;
    double newSeparatingSpeed = -this->restitition * separatingSpeed;
    double deltaSpeed         = newSeparatingSpeed - separatingSpeed;
    double totalMass          = (double)1 / this->particles[0]->getMass();
    if (this->particles[1]) totalMass += (double)1 / this->particles[1]->getMass();

    if (totalMass <= 0) return;
    double impulseMagnitude = deltaSpeed / totalMass;
    MyVector3 impulse       = this->contactNormal * impulseMagnitude;

    MyVector3 newVelocity0  = impulse * ((double)1 / this->particles[0]->getMass());
    this->particles[0]->setVelocity(this->particles[0]->getVelocity() + newVelocity0);
    MyVector3 newVelocity1 = impulse * ((double)-1 / this->particles[1]->getMass());
    this->particles[1]->setVelocity(this->particles[1]->getVelocity() + newVelocity1);
}
void MyParticleContact::resolve(double time) { this->resolveVelocity(time); }

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
double MyParticleContact::getRestitition() { return this->restitition; }
MyVector3 MyParticleContact::getContactNormal() { return this->contactNormal; }