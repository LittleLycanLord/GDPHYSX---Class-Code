#include "OrthographicCamera.hpp"

using namespace models;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
OrthographicCamera::OrthographicCamera(std::string name,
                                       glm::vec3 position,
                                       glm::vec3 viewCenter,
                                       float left,
                                       float right,
                                       float bottom,
                                       float top,
                                       float near,
                                       float far)
    : Camera(name, glm::ortho(left, right, bottom, top, near, far), position, viewCenter) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void OrthographicCamera::OtherInputs(int key, int action, int mods) {}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
// namespace models
