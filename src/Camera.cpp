#include "Camera.h"

Camera::Camera(int viewportWidth, int viewportHeight, glm::vec3 position)
{
	this->viewportWidth = viewportWidth;
	this->viewportHeight = viewportHeight;
	this->position = position;
}

Camera::~Camera()
{

}

void Camera::init(float fov, float nearPlane, float farPlane)
{
	this->fov = fov;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;
}

void Camera::matrix(Shader& shader, const char* uniform)
{
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	view = glm::lookAt(this->position, this->position + this->orientation, this->up);
	proj = glm::perspective(glm::radians(this->fov), (float)this->viewportWidth / this->viewportHeight, this->nearPlane, this->farPlane);

	// export matrix to the shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(proj * view));
}

void Camera::setPosition(glm::vec3 position)
{
	this->position = position;
}

void Camera::setFov(float fov)
{
	this->fov = fov;
}

void Camera::setNearPlane(float nearPlane)
{
	this->nearPlane = nearPlane;
}

void Camera::setFarPlane(float farPlane)
{
	this->farPlane = farPlane;
}

glm::vec3 Camera::getPosition()
{
	return this->position;
}