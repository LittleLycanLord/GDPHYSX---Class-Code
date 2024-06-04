#pragma once
#include "chrono"
#include "string"
using namespace std::chrono_literals;

//* - - - - - DEBUG - - - - -
const bool DEBUG_MODE                           = false;
const bool DEBUG_MODE_CAMERA_MOVEMENT           = true;
const bool DEBUG_MODE_MODEL_TINTING             = false;
const bool DEBUG_MODE_MATH                      = true;
const bool DEBUG_MODE_PHYSICS                   = true;
const bool DEBUG_MODE_PROGRAMMING_CHALLENGE_1   = false;
const int COUT_PRECISION                        = 2;
//* - - - - - END OF DEBUG - - - - -

//* - - - - - ENGINE SETTINGS - - - - -
const int WINDOW_WIDTH                          = 700;
const int WINDOW_HEIGHT                         = 700;
const bool DRAW_SKYBOX                          = false;
const bool ONE_PIXEL_PER_METER                  = true;
const bool POSITIVE_Y_ONLY                      = false;
const bool ORIGIN_MARKER                        = false;
const double FRAMERATE                          = 60.0f;
constexpr std::chrono::nanoseconds TIMESTEP     = 16ms;

const std::string WINDOW_NAME                   = "PC01 Conrad Amadeus Carmelo C. Ubay";

const std::string LIGHTING_FRAGMENT_SHADER_PATH = "Shaders/main.frag";
const std::string LIGHTING_VERTEX_SHADER_PATH   = "Shaders/main.vert";
const std::string SKYBOX_FRAGMENT_SHADER_PATH   = "Shaders/skybox.frag";
const std::string SKYBOX_VERTEX_SHADER_PATH     = "Shaders/skybox.vert";

const std::string SKYBOX_RIGHT_TEXTURE_PATH     = "Assets/Skybox/underwater_rt.png";
const std::string SKYBOX_LEFT_TEXTURE_PATH      = "Assets/Skybox/underwater_lf.png";
const std::string SKYBOX_TOP_TEXTURE_PATH       = "Assets/Skybox/underwater_up.png";
const std::string SKYBOX_BOTTOM_TEXTURE_PATH    = "Assets/Skybox/underwater_dn.png";
const std::string SKYBOX_FRONT_TEXTURE_PATH     = "Assets/Skybox/underwater_ft.png";
const std::string SKYBOX_BACK_TEXTURE_PATH      = "Assets/Skybox/underwater_bk.png";
//* - - - - - END OF ENGINE SETTINGS - - - - -

//* - - - - - GAME SETTINGS - - - - -
//* - - - - - END OF GAME SETTINGS - - - - -