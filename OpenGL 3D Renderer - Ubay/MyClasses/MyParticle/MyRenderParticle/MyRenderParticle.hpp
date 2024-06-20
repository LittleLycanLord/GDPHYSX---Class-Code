#pragma once
#include "../../My3DModel/My3DModel.hpp"
#include "../MyParticle.hpp"
#include "stdafx.h"

using namespace rendering;

namespace MyPhysics {
class MyRenderParticle : public MyParticle {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
protected:
    My3DModel* model;
    MyVector3 tint;

    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    // Default Model with Custom Color
    MyRenderParticle(MyVector3 tint);
    MyRenderParticle(double mass, MyVector3 tint);
    MyRenderParticle(double mass, MyVector3 position, MyVector3 tint);

    // Custom Model with Default Color
    //  MyRenderParticle(std::string name, std::string modelPath, std::string texturePath);
    //  MyRenderParticle(std::string name, std::string modelPath, std::string texturePath, double
    //  mass); MyRenderParticle(std::string name, std::string modelPath, std::string texturePath,
    //  double mass, MyVector3 position);

    // Custom Model with Custom Color
    // MyRenderParticle(std::string name, std::string modelPath, std::string texturePath, MyVector3
    // tint); MyRenderParticle(std::string name, std::string modelPath, std::string texturePath,
    // double mass, MyVector3 tint); MyRenderParticle(std::string name, std::string modelPath,
    // std::string texturePath, double mass, MyVector3 position, MyVector3 tint);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
protected:
    void updateModel();
    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    My3DModel* getModel3D();
    void setColor(MyVector3 tint);
    MyVector3 getColor();
};
}  // namespace MyPhysics