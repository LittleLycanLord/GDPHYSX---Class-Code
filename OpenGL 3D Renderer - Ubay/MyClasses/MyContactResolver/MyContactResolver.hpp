#pragma once
#include "../MyParticleContact/MyParticleContact.hpp"
#include "../MyVectors/MyVector3.hpp"
#include "map"
#include "stdafx.h"

using namespace rendering;
using namespace std;

namespace MyPhysics {
class MyContactResolver {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
private:
    unsigned int maxIterations;
    unsigned int currentIterations = 0;

    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    MyContactResolver(unsigned int maxIterations);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
public:
    vector<MyParticleContact*> resolveContacts(vector<MyParticleContact*> contacts, double time);

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
};
}  // namespace MyPhysics