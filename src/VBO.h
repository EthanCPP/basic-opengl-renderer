#pragma once
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <vector>

#include "Vertex.h"

class VBO
{
public:
	VBO(std::vector<Vertex>& vertices);
	~VBO();

	void bind();
	void unbind();

	GLuint ID;
};

