#pragma once
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