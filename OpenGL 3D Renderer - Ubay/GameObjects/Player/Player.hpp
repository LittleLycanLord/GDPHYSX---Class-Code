#pragma once
#include "../Cameras/Camera.hpp"
#include "../Cameras/OrthographicCamera/OrthographicCamera.hpp"
#include "../Cameras/PerspectiveCamera/PerspectiveCamera.hpp"
#include "../Lights/DirectionalLight/DirectionalLight.hpp"
#include "../Lights/PointLight/PointLight.hpp"
#include "../Lights/SpotLight/SpotLight.hpp"
#include "../Model3D/Model3D.hpp"
#include "../MyNormal/MyNormal.hpp"
#include "../MyTexture/MyTexture.hpp"
#include "cstdlib"
#include "glm/gtx/transform.hpp"
#include "iomanip"
// // clang-format off
// #include "glad/glad.h"
// #include "GLFW/glfw3.h"
// // clang-format on
#include "stdafx.h"

namespace models {
class Player {
    //* ╔════════════╗
    //* ║ Attributes ║
    //* ╚════════════╝
protected:
    Model3D* model;
    PerspectiveCamera* firstPersonView;
    PerspectiveCamera* thirdPersonView;
    Camera* activeCamera;
    float turnInput;
    float yInput;
    float zInput;
    int lightIntensity;

    //* ╔═══════════════════════════════╗
    //* ║ Constructors & Deconstructors ║
    //* ╚═══════════════════════════════╝
public:
    Player();

    //* ╔═════════╗
    //* ║ Methods ║
    //* ╚═════════╝
public:
    void playerKeyboardInput(int key, int action);
    void playerMouseInput();
    void movePlayer();
    void turnPlayer();
    void resetInputs();
    void haveCamerasFollowModel();

    //* ╔═══════════════════╗
    //* ║ Getters & Setters ║
    //* ╚═══════════════════╝
public:
    Model3D* getModel();
    PerspectiveCamera* getFirstPersonView();
    PerspectiveCamera* getThirdPersonView();
    Camera* getActiveCamera();
};
}  // namespace models