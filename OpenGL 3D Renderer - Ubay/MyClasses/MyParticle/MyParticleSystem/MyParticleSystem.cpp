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
            //? Random Color
            random_device randomDeviceColor;
            mt19937 aRandomColor(randomDeviceColor());
            uniform_real_distribution<double> generateColor(0.0f, 1.0f);
            MyRenderParticle* newParticle =
                new MyRenderParticle(MyVector3(generateColor(aRandomColor),
                                               generateColor(aRandomColor),
                                               generateColor(aRandomColor)));

            //* - - - - - PARTICLE DETAILS - - - - -
            //? Random Force
            random_device randomDeviceXZ;
            mt19937 aRandomXZ(randomDeviceXZ());
            uniform_int_distribution<int> generateXZ(-500, 500);
            random_device randomDeviceY;
            mt19937 aRandomY(randomDeviceY());
            uniform_int_distribution<int> generateY(100, 2000);
            //? Random Scale
            random_device randomDeviceScale;
            mt19937 aRandomScale(randomDeviceScale());
            uniform_real_distribution<double> generateScale(2.0f, 10.0f);
            //? Random Lifetime
            random_device randomDeviceLifetime;
            mt19937 aRandomLifetime(randomDeviceLifetime());
            uniform_real_distribution<double> generateLifetime(1.0f, 10.0f);

            newParticle->addForce(
                MyVector3(generateXZ(aRandomXZ), generateY(aRandomY), generateXZ(aRandomXZ)));
            newParticle->getModel3D()->setScale((glm::vec3)MyVector3(generateScale(aRandomScale)));
            newParticle->setUsesGravity(true);
            MyDragGenerator* drag = new MyDragGenerator(0.9, 0.9);
            this->physicsWorld->getForceRegistry()->add(newParticle, drag);
            newParticle->setLifetime(generateLifetime(aRandomLifetime));
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