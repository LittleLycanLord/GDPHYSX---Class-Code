#pragma once
#include "../Camera.hpp"
#include "stdafx.h"

namespace models {
class PerspectiveCamera : public Camera {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
private:
    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    PerspectiveCamera(std::string name,
                      glm::vec3 position,
                      glm::vec3 viewCenter,
                      float fieldOfView,
                      float farClippingPlane);

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
public:
    void OtherInputs(int key, int action, int mods);

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
};
}  // namespace models