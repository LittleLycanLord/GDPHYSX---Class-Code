#pragma once
#include "../MyNormal/MyNormal.hpp"
#include "../MyVectors/MyVector3.hpp"
#include "stdafx.h"

namespace MyPhysics {
class MyParticle {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
protected:
    double mass;
    MyVector3 position;
    MyVector3 velocity;
    MyVector3 acceleration;

    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    MyParticle();
    MyParticle(double mass);
    MyParticle(double mass, MyVector3 position);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
protected:
    void updatePosition(double time);
    void updateVelocity(double time);

public:
    void update(double time);

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    double getMass();
    void setMass(double mass);
    MyVector3 getPosition();
    void setPosition(MyVector3 position);
    void setPosition(double x, double y, double z);
    MyVector3 getVelocity();
    void setVelocity(MyVector3 velocity);
    void setVelocity(double x, double y, double z);
    MyVector3 getAcceleration();
    void setAcceleration(MyVector3 acceleration);
    void setAcceleration(double x, double y, double z);
};
}  // namespace MyPhysics