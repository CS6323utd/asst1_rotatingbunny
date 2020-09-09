#include "Animation.h"

Animation::Animation() {
	this->m_model_mat = glm::mat4(1.0f);
}

Animation::~Animation() {
}

void Animation::init() {
	reset();
}

void Animation::reset() {
	m_model_mat = glm::mat4(1.0f);
	m_model_mat = glm::translate(m_model_mat, glm::vec3(5.0, 0.0, 0.0));

	//////////
	// Task 5: Reset
	// Have a “Reset” button that can reset the bunny to the initial state
}

void Animation::update(float delta_time) {
	//////////
	// Task 3: implement the update function for rotation
}
