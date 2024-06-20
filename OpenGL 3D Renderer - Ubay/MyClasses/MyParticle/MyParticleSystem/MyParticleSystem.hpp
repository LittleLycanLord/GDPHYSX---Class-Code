#pragma once
#include "../../MyPhysicsWorld/MyPhysicsWorld.hpp"
#include "../MyParticle.hpp"
#include "../MyRenderParticle/MyRenderParticle.hpp"
#include "random"
#include "stdafx.h"

using namespace rendering;

namespace MyPhysics {
class MyParticleSystem : public MyParticle {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
protected:
    MyPhysicsWorld* physicsWorld;
    list<MyParticle*> childParticles;
    double lifetime   = 0.0f;
    int particleCount = 10;

    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    MyParticleSystem(MyVector3 position,
                     double lifetime,
                     int particleCount,
                     MyPhysicsWorld* physicsWorld);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
protected:
    void update(double time, int physicsUpdateCount);

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    int getParticleCount();
    void setParticleCount(int particleCount);
};
}  // namespace MyPhysics