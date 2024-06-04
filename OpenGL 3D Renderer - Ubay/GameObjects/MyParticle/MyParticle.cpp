#include "MyParticle.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyParticle::MyParticle()
    : mass(0.0f),
      isDestroyed(false),
      usesGravity(false),
      position(0.0f),
      velocity(0.0f),
      acceleration(0.0f) {}
MyParticle::MyParticle(double mass)
    : mass(mass),
      isDestroyed(false),
      usesGravity(false),
      position(0.0f),
      velocity(0.0f),
      acceleration(0.0f) {}
MyParticle::MyParticle(double mass, MyVector3 position)
    : mass(mass),
      isDestroyed(false),
      usesGravity(false),
      position(position),
      velocity(0.0f),
      acceleration(0.0f) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void MyParticle::updateModel() {}
void MyParticle::updatePosition(double time) {
    this->position =
        this->position + (this->velocity * time) + ((this->acceleration * time * time) / 2.0f);
    this->updateModel();
}
void MyParticle::updateVelocity(double time) {
    this->velocity = this->velocity + (this->acceleration * time);
}

void MyParticle::update(double time) {
    this->updatePosition(time);
    this->updateVelocity(time);
}
void MyParticle::destroy() { this->isDestroyed = true; }

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
double MyParticle::getMass() { return this->mass; }
void MyParticle::setMass(double mass) { this->mass = mass; }
bool MyParticle::getIsDestroyed() { return this->isDestroyed; }
bool MyParticle::getUsesGravity() { return this->usesGravity; }
void MyParticle::setUsesGravity(bool usesGravity) { this->usesGravity = usesGravity; }
MyVector3 MyParticle::getPosition() { return this->position; }
void MyParticle::setPosition(MyVector3 position) { this->position = position; }
void MyParticle::setPosition(double x, double y, double z) { this->position = MyVector3(x, y, z); }
MyVector3 MyParticle::getVelocity() { return this->velocity; }
void MyParticle::setVelocity(MyVector3 velocity) { this->velocity = velocity; }
void MyParticle::setVelocity(double x, double y, double z) { this->velocity = MyVector3(x, y, z); }
MyVector3 MyParticle::getAcceleration() { return this->acceleration; }
void MyParticle::setAcceleration(MyVector3 acceleration) { this->acceleration = acceleration; }
void MyParticle::setAcceleration(double x, double y, double z) {
    this->acceleration = MyVector3(x, y, z);
}