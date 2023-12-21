#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "Shader.h"

class Camera
{
public:
	Camera(int viewportWidth, int viewportHeight, glm::vec3 position);
	~Camera();

	void init(float fov, float nearPlane, float farPlane);
	void matrix(Shader& shader, const char* uniform);

	void setPosition(glm::vec3 position);
	void setFov(float fov);
	void setNearPlane(float nearPlane);
	void setFarPlane(float farPlane);

	glm::vec3 getPosition();
private:
	int viewportWidth;
	int viewportHeight;

	glm::vec3 position;
	float fov;
	float nearPlane;
	float farPlane;

	// normalised directionals
	glm::vec3 orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
};

