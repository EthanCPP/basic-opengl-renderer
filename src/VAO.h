#pragma once
#include <glad/glad.h>

#include "VBO.h"

class VAO
{
public:
	VAO();
	~VAO();

	void linkAttribute(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
	void bind();
	void unbind();

	GLuint ID;
};

