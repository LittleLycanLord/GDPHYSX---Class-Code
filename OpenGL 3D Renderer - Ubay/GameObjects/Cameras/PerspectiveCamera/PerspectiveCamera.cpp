#include "PerspectiveCamera.hpp"

using namespace models;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
PerspectiveCamera::PerspectiveCamera(std::string name,
                                     glm::vec3 position,
                                     glm::vec3 viewCenter,
                                     float fieldOfView,
                                     float farClippingPlane)
    : Camera(name,
             glm::perspective(glm::radians(fieldOfView),
                              float(WINDOW_WIDTH / WINDOW_HEIGHT),
                              0.1f,
                              farClippingPlane),
             position,
             viewCenter) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void PerspectiveCamera::OtherInputs(int key, int action, int mods) {}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
// namespace models
