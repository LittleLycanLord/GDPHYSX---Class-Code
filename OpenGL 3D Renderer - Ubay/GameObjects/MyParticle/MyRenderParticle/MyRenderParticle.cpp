#include "MyRenderParticle.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
// Default Model with Custom Color
MyRenderParticle::MyRenderParticle(MyVector3 tint)
    : MyParticle(),
      model3d(new Model3D("DEFAULT PARTICLE",
                          DEFAULT_PARTICLE_MODEL_PATH,
                          DEFAULT_PARTICLE_TEXTURE_PATH,
                          "",
                          glm::vec3(tint),
                          glm::vec3(0.0f, 0.0f, 0.0f),
                          glm::mat4(1.0f),
                          glm::vec3(3.0f),
                          glm::vec3(0.0f))),
      tint(tint) {}
MyRenderParticle::MyRenderParticle(double mass, MyVector3 tint)
    : MyParticle(mass),
      model3d(new Model3D("DEFAULT PARTICLE",
                          DEFAULT_PARTICLE_MODEL_PATH,
                          DEFAULT_PARTICLE_TEXTURE_PATH,
                          "",
                          glm::vec3(tint),
                          glm::vec3(0.0f, 0.0f, 0.0f),
                          glm::mat4(1.0f),
                          glm::vec3(3.0f),
                          glm::vec3(0.0f))),
      tint(tint) {}
MyRenderParticle::MyRenderParticle(double mass, MyVector3 position, MyVector3 tint)
    : MyParticle(mass, position),
      model3d(new Model3D("DEFAULT PARTICLE",
                          DEFAULT_PARTICLE_MODEL_PATH,
                          DEFAULT_PARTICLE_TEXTURE_PATH,
                          "",
                          glm::vec3(tint),
                          glm::vec3(position),
                          glm::mat4(1.0f),
                          glm::vec3(3.0f),
                          glm::vec3(0.0f))),
      tint(tint) {}

// Custom Model with Default Color
// MyRenderParticle::MyRenderParticle(std::string name, std::string modelPath, std::string
// texturePath)
//     : MyParticle(),
//       model3d(new Model3D(name,
//                                  modelPath,
//                                  texturePath,
//                                  "",
//                                  glm::vec3(0.0f, 0.0f, 0.0f),
//                                  glm::mat4(1.0f),
//                                  glm::vec3(3.0f),
//                                  glm::vec3(0.0f))),
//       tint(MyVector3(1.0f, 1.0f, 1.0f)) {}
// MyRenderParticle::MyRenderParticle(std::string name,
//                                    std::string modelPath,
//                                    std::string texturePath,
//                                    double mass)
//     : MyParticle(mass),
//       model3d(new Model3D(name,
//                                  modelPath,
//                                  texturePath,
//                                  "",
//                                  glm::vec3(0.0f, 0.0f, 0.0f),
//                                  glm::mat4(1.0f),
//                                  glm::vec3(3.0f),
//                                  glm::vec3(0.0f))),
//       tint(MyVector3(1.0f, 1.0f, 1.0f)) {}
// MyRenderParticle::MyRenderParticle(std::string name,
//                                    std::string modelPath,
//                                    std::string texturePath,
//                                    double mass,
//                                    MyVector3 position)
//     : MyParticle(mass, position),
//       model3d(new Model3D(name,
//                                  modelPath,
//                                  texturePath,
//                                  "",
//                                  glm::vec3(position),
//                                  glm::mat4(1.0f),
//                                  glm::vec3(3.0f),
//                                  glm::vec3(0.0f))),
//       tint(MyVector3(1.0f, 1.0f, 1.0f)) {}

// // Custom Model with Custom Color
// MyRenderParticle::MyRenderParticle(std::string name,
//                                    std::string modelPath,
//                                    std::string texturePath,
//                                    MyVector3 tint)
//     : MyParticle(),
//       model3d(new Model3D(name,
//                                  modelPath,
//                                  texturePath,
//                                  "",
//                                  glm::vec3(0.0f, 0.0f, 0.0f),
//                                  glm::mat4(1.0f),
//                                  glm::vec3(3.0f),
//                                  glm::vec3(0.0f))),
//       tint(tint) {}
// MyRenderParticle::MyRenderParticle(std::string name,
//                                    std::string modelPath,
//                                    std::string texturePath,
//                                    double mass,
//                                    MyVector3 tint)
//     : MyParticle(mass),
//       model3d(new Model3D(name,
//                                  modelPath,
//                                  texturePath,
//                                  "",
//                                  glm::vec3(0.0f, 0.0f, 0.0f),
//                                  glm::mat4(1.0f),
//                                  glm::vec3(3.0f),
//                                  glm::vec3(0.0f))),
//       tint(tint) {}
// MyRenderParticle::MyRenderParticle(std::string name,
//                                    std::string modelPath,
//                                    std::string texturePath,
//                                    double mass,
//                                    MyVector3 position,
//                                    MyVector3 tint)
//     : MyParticle(mass, position),
//       model3d(new Model3D(name,
//                                  modelPath,
//                                  texturePath,
//                                  "",
//                                  glm::vec3(position),
//                                  glm::mat4(1.0f),
//                                  glm::vec3(3.0f),
//                                  glm::vec3(0.0f))),
//       tint(tint) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
void MyRenderParticle::updateModel() { this->model3d->setPosition(glm::vec3(this->position)); }

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝
Model3D* MyRenderParticle::getModel3D() { return this->model3d; }
void MyRenderParticle::setColor(MyVector3 tint) { this->tint = tint; }
MyVector3 MyRenderParticle::getColor() { return this->tint; }