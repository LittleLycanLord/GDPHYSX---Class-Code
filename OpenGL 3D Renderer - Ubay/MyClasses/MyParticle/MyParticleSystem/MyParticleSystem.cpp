#include "MyParticleSystem.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyParticleSystem::MyParticleSystem(MyVector3 position,
                                   double lifetime,
                                   int particleCount,
                                   MyPhysicsWorld* physicsWorld)
    : MyParticle(position),
      lifetime(lifetime),
      particleCount(particleCount),
      physicsWorld(physicsWorld) {}
//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void MyParticleSystem::update(double time, int physicsUpdateCount) {
    if (this->lifetime <= 0) {
        for (MyParticle* particle : this->childParticles) {
            particle->destroy();
        }
        this->destroy();
    } else {
        if (this->particleCount > 0) {
            cout << "New particle!" << endl;
            MyRenderParticle* newParticle = new MyRenderParticle(1.0f, 1.0f, 1.0f);

            //* - - - - - PARTICLE DETAILS - - - - -
            random_device randomDeviceXZ;
            mt19937 aRandomXZ(randomDeviceXZ());
            uniform_int_distribution<> generateXZ(-5000, 5000);
            random_device randomDeviceY;
            mt19937 aRandomY(randomDeviceY());
            uniform_int_distribution<> generateY(5000, 8000);

            newParticle->addForce(
                MyVector3(generateXZ(aRandomXZ), generateXZ(aRandomY), generateXZ(aRandomXZ)));
            newParticle->setUsesGravity(true);
            newParticle->setLifetime(6.0f);
            //* - - - - - END OF PARTICLE DETAILS - - - - -

            this->physicsWorld->addParticle(newParticle);
            this->particleCount--;
        }
        this->lifetime -= time;
    }
}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
int MyParticleSystem::getParticleCount() { return this->particleCount; }
void MyParticleSystem::setParticleCount(int particleCount) { this->particleCount = particleCount; }