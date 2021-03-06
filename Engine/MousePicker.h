#ifndef MOUSEPICKER_H
#define MOUSEPICKER_H
#include "basic.h"
#include <GLFW/glfw3.h>
#include "Geometry.h"
#include "camera.h"
#include "RigidBody.h"
#include "OcTree.h"
#include "vendor\imgui\imgui.h"
#include "Ray.h"

extern renderer::camera camera;
extern const unsigned int SCR_WIDTH;
extern const unsigned int SCR_HEIGHT;

class MousePicker {
private:
	Ray m_currentRay;
	RigidBody** modifyBody;
	bool* read;
public:
	MousePicker(RigidBody** modifyBody ,bool* read) : modifyBody(modifyBody), read(read) {}
	inline glm::vec2 getNormalizedDeviceCoords(const glm::vec2& ve) {
		return glm::vec2(2 * ve.x / SCR_WIDTH - 1, - 2 * ve.y / SCR_HEIGHT + 1);
	} 
	glm::vec4 toEyeCoords(glm::vec4 clipCoords);
	glm::vec3 toWorldCoord(glm::vec4 eyeCoords);
	void update(OcTree* tree);
	inline const Ray& getRay() const { return m_currentRay; }
};
#endif // !MOUSEPICKER_H
