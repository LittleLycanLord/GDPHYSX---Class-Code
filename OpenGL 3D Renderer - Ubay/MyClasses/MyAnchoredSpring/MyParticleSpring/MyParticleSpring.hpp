#pragma once
#include "../MyAnchoredSpring.hpp"
#include "stdafx.h"

namespace MyPhysics {

using namespace std;

class MyParticleSpring : public MyAnchoredSpring {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
protected:
    MyParticle* otherParticle;
    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    MyParticleSpring(MyParticle* otherParticle, double springConstant, double restLength);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
public:
private:
    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
};
}  // namespace MyPhysics