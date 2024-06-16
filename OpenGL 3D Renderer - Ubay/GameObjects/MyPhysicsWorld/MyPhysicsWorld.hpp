#pragma once
#include "../MyForceGenerator/MyGravityGenerator/MyGravityGenerator.hpp"
#include "../MyForceRegistry/MyForceRegistry.hpp"
#include "../MyParticle/MyParticle.hpp"
#include "stdafx.h"

namespace MyPhysics {

using namespace std;

class MyPhysicsWorld {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
public:
    list<MyParticle*> particles;
    int updateCount;
    MyForceRegistry forceRegistry;
    MyGravityGenerator gravityGenerator;

    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    MyPhysicsWorld();

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
public:
    void update(float time);
    void addParticle(MyParticle* particleToAdd);

private:
    void updateParticleList();

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
};
}  // namespace MyPhysics