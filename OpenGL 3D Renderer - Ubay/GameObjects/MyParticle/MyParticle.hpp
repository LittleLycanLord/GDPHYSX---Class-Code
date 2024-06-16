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
    double mass;         //? in kg
    MyVector3 position;  //? in m

    double damping   = DEFAULT_DAMPING;  //? [0 -> 1]; the lower the value, the higher the drag
    bool isDestroyed = false;
    bool usesGravity = false;
    double magnitudeVelocity   = 0.0f;         //? in m/s
    MyVector3 totalVelocity    = MyVector3();  //? in m/s
    MyVector3 averageVelocity  = MyVector3();  //? in m/s
    MyVector3 velocity         = MyVector3();  //? in m/s
    MyVector3 acceleration     = MyVector3();  //? in m/s^2

    MyVector3 accumulatedForce = MyVector3();  //? in kg m/s^2

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
    virtual void updateModel();
    void updatePosition(double time);
    void updateVelocity(double time);
    void updateAverageVelocity(int physicsUpdateCount);

public:
    void update(double time, int physicsUpdateCount);
    void moveTowards(MyVector3 target, double magnitudeVelocity);
    void addForce(MyVector3 force);
    void resetForce();
    void stop();
    void destroy();

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    double getMass();
    void setMass(double mass);
    double getDamping();
    void setDamping(double damping);
    bool getIsDestroyed();
    bool getUsesGravity();
    void setUsesGravity(bool usesGravity);
    MyVector3 getPosition();
    void setPosition(MyVector3 position);
    void setPosition(double x, double y, double z);
    double getMagnitudeVelocity();
    MyVector3 getAverageVelocity();
    MyVector3 getVelocity();
    void setVelocity(MyVector3 velocity);
    void setVelocity(double x, double y, double z);
    MyVector3 getAcceleration();
    void setAcceleration(MyVector3 acceleration);
    void setAcceleration(double x, double y, double z);
};
}  // namespace MyPhysics