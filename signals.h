#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "constants.h"


//executed upon SIG_ACTION_MOVEMENT
void sig_action_movement_down(glm::vec3& mov, bool& signal);
void sig_action_movement_W(glm::vec3& mov, bool& signal);
void sig_action_movement_S(glm::vec3& mov, bool& signal);
void sig_action_movement_A(glm::vec3& mov, bool& signal);
void sig_action_movement_D(glm::vec3& mov, bool& signal);
void sig_action_rotation_xpos_u(float& rot, bool& signal);
void sig_action_rotation_xneg_m(float& rot, bool& signal);
void sig_action_rotation_ypos_h(float& rot, bool& signal);
void sig_action_rotation_yneg_k(float& rot, bool& signal);
void sig_action_rotation_zpos_n(float& rot, bool& signal);
void sig_action_rotation_zneg_i(float& rot, bool& signal);
void sig_debug_occupancy(bool& signal);