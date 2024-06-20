#include "MyRenderParticle.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
// Default Model with Custom Color
MyRenderParticle::MyRenderParticle(MyVector3 tint)
    : MyParticle(),
      model(new My3DModel("DEFAULT PARTICLE",
                          DEFAULT_PARTICLE_MODEL_PATH,
                          DEFAULT_PARTICLE_TEXTURE_PATH,
                          "",
                          glm::vec3(tint),
                          glm::vec3(0.0f, 0.0f, 0.0f),
                          glm::mat4(1.0f),
                          glm::vec3(PARTICLE_SCALE),
                          glm::vec3(0.0f))),
      tint(tint) {
    this->model->loadModel();
}
MyRenderParticle::MyRenderParticle(double mass, MyVector3 tint)
    : MyParticle(mass),
      model(new My3DModel("DEFAULT PARTICLE",
                          DEFAULT_PARTICLE_MODEL_PATH,
                          DEFAULT_PARTICLE_TEXTURE_PATH,
                          "",
                          glm::vec3(tint),
                          glm::vec3(0.0f, 0.0f, 0.0f),
                          glm::mat4(1.0f),
                          glm::vec3(PARTICLE_SCALE),
                          glm::vec3(0.0f))),
      tint(tint) {
    this->model->loadModel();
}
MyRenderParticle::MyRenderParticle(double mass, MyVector3 position, MyVector3 tint)
    : MyParticle(mass, position),
      model(new My3DModel("DEFAULT PARTICLE",
                          DEFAULT_PARTICLE_MODEL_PATH,
                          DEFAULT_PARTICLE_TEXTURE_PATH,
                          "",
                          glm::vec3(tint),
                          glm::vec3(position),
                          glm::mat4(1.0f),
                          glm::vec3(PARTICLE_SCALE),
                          glm::vec3(0.0f))),
      tint(tint) {
    this->model->loadModel();
}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void MyRenderParticle::updateModel() {
    if (this->isDestroyed) {
        this->model->destroy();
    } else {
        this->model->setPosition(glm::vec3(this->position));
    }
}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
My3DModel* MyRenderParticle::getModel3D() { return this->model; }
void MyRenderParticle::setColor(MyVector3 tint) { this->tint = tint; }
MyVector3 MyRenderParticle::getColor() { return this->tint; }