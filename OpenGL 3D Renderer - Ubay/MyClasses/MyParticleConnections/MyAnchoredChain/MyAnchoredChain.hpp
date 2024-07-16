#pragma once
#include "../../My3DModel/My3DModel.hpp"
#include "../../MyParticle/MyRenderParticle/MyRenderParticle.hpp"
#include "../../MyParticleLink/MyRod/MyRod.hpp"
#include "../../MySprings/MyAnchoredSpring/MyAnchoredSpring.hpp"
#include "../../MyVectors/MyVector3.hpp"
#include "stdafx.h"

namespace MyPhysics {

using namespace std;
using namespace rendering;

class MyAnchoredChain {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
protected:
    My3DModel* model;
    MyVector3 tint;
    MyVector3 anchorPoint;
    unsigned int segmentCount;
    double segmentLength;
    double totalLength;
    bool usesGravity;

    MyAnchoredSpring* headSegment;
    vector<MyParticle*> particles;
    vector<MyRod*> segments;
    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    //? Unknown chain segment count
    MyAnchoredChain(My3DModel* model,
                    MyVector3 tint,
                    MyVector3 anchorPoint,
                    double segmentLength,
                    double totalLength,
                    bool usesGravity);
    //? Unknown chain segment length
    MyAnchoredChain(My3DModel* model,
                    MyVector3 tint,
                    MyVector3 anchorPoint,
                    unsigned int segmentCount,
                    double totalLength,
                    bool usesGravity);
    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
public:
    void addParticle(MyParticle* particle);
    void addSegment(MyRod* rod);
    void setHeadSegment(MyAnchoredSpring* anchoredSpring);

private:
    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    My3DModel* getModel();
    MyVector3 getTint();
    MyVector3 getAnchorPoint();
    unsigned int getSegmentCount();
    double getSegmentLength();
    double getTotalLength();
    bool getUsesGravity();

    MyAnchoredSpring* getHeadSegment();
    vector<MyParticle*> getParticles();
    vector<MyRod*> getSegments();
};
}  // namespace MyPhysics