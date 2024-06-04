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
    bool isDestroyed;
    bool usesGravity;
    MyVector3 position;
    double magnitudeVelocity;
    MyVector3 totalVelocity;
    MyVector3 averageVelocity;
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
    virtual void updateModel();
    void updatePosition(double time);
    void updateVelocity(double time);
    void updateAverageVelocity(int physicsUpdateCount);

public:
    void update(double time, int physicsUpdateCount);
    void moveTowards(MyVector3 target, double magnitudeVelocity);
    void stop();
    void destroy();

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    double getMass();
    void setMass(double mass);
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