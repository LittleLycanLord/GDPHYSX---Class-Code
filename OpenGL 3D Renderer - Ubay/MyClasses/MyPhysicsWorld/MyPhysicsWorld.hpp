#pragma once
#include "../My3DModel/My3DModel.hpp"
#include "../MyContactResolver/MyContactResolver.hpp"
#include "../MyForceGenerator/MyGravityGenerator/MyGravityGenerator.hpp"
#include "../MyForceRegistry/MyForceRegistry.hpp"
#include "../MyParticle/MyParticle.hpp"
#include "../MyParticle/MyRenderParticle/MyRenderParticle.hpp"
#include "../MyParticleContact/MyParticleContact.hpp"
#include "stdafx.h"

using namespace std;
using namespace rendering;

namespace MyPhysics {
class MyPhysicsWorld {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
public:
    list<My3DModel*>* renderingList;
    list<MyParticle*> particles;
    vector<MyParticleContact*> contacts;
    int updateCount;
    MyForceRegistry forceRegistry;
    MyGravityGenerator gravityGenerator;
    MyContactResolver contactResolver;

    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    MyPhysicsWorld(list<My3DModel*>* renderingList);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
public:
    void update(double time);
    void addParticle(MyParticle* particleToAdd);
    void addParticleContact(MyParticle* particle0, MyParticle* particle1, double restitution);

private:
    void updateParticleList();
    void updateGravity(MyParticle* particle);

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    list<My3DModel*>* getRenderingList();
    vector<MyParticle*> getParticleListAsVector();
    MyForceRegistry* getForceRegistry();
};
}  // namespace MyPhysics