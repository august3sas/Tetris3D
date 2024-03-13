#include "signals.h"
//----------------upon game tick
void sig_action_movement_down(glm::vec3& mov, bool& signal) {
	mov = mov + glm::vec3(0.0f, -1.0f, 0.0f);
	signal = false;
}
//----------------X axis----------
void sig_action_movement_W(glm::vec3& mov, bool& signal) {
	mov = mov + glm::vec3(1.0f, 0.0f, 0.0f);
	signal = false;
}
void sig_action_movement_S(glm::vec3& mov, bool& signal) {
	mov = mov + glm::vec3(-1.0f, 0.0f, 0.0f);
	signal = false;
}
//----------------Z axis----------
void sig_action_movement_A(glm::vec3& mov, bool& signal) {
	mov = mov + glm::vec3(0.0f, 0.0f, -1.0f);
	signal = false;
}
void sig_action_movement_D(glm::vec3& mov, bool& signal) {
	mov = mov + glm::vec3(0.0f, 0.0f, 1.0f);
	signal = false;
}

void sig_action_rotation_xpos_u(float& rot, bool& signal) {
	rot = rot + PI / 2;
	signal = false;
}
void sig_action_rotation_xneg_m(float& rot, bool& signal) {
	rot = rot - PI / 2;
	signal = false;
}
void sig_action_rotation_ypos_h(float& rot, bool& signal) {
	rot = rot + PI / 2;
	signal = false;
}

void sig_action_rotation_yneg_k(float& rot, bool& signal) {
	rot = rot - PI / 2;
	signal = false;
}

void sig_action_rotation_zpos_n(float& rot, bool& signal) {
	rot = rot + PI / 2;
	signal = false;
}
void sig_action_rotation_zneg_i(float& rot, bool& signal) {
	rot = rot - PI / 2;
	signal = false;
}
void sig_debug_occupancy(bool& signal) {
	signal = false;
}