#pragma once
#include "../MyParticle/MyParticle.hpp"
#include "../MyVectors/MyVector3.hpp"
#include "stdafx.h"

using namespace rendering;
using namespace std;

namespace MyPhysics {
class MyParticleContact {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
private:
    MyParticle* particles[2];
    double restitition;
    MyVector3 contactNormal;
    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    MyParticleContact(MyParticle* particles[], double restitition, MyVector3 contactNormal);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
protected:
    void resolveVelocity(double time);

public:
    double calculateSeparatingSpeed();
    void resolve(double time);

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    double getRestitition();
    MyVector3 getContactNormal();
};
}  // namespace MyPhysics