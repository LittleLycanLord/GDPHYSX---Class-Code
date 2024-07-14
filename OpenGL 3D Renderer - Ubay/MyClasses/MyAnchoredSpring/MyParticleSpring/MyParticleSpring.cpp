#include "MyParticleSpring.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyParticleSpring::MyParticleSpring(MyParticle* otherParticle,
                                   double springConstant,
                                   double restLength)
    : otherParticle(otherParticle),
      MyAnchoredSpring(otherParticle->getPosition(), springConstant, restLength) {}
//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
