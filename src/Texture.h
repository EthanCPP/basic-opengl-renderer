#pragma once
#include <glad/glad.h>
#include <stb/stb_image.h>

#include "Shader.h"

class Texture
{
public:
	Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
	~Texture();

	void assignUnit(Shader& shader, const char* uniform, GLuint unit);
	void bind();
	void unbind();

private:
	GLuint ID;
	GLenum type;
};

