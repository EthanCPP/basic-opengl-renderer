#include "Texture.h"

Texture::Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType)
{
	this->type = texType;

	// store width, height, and number of colour channels
	int imgWidth, imgHeight, numColCh;

	stbi_set_flip_vertically_on_load(true);

	unsigned char* bytes = stbi_load(image, &imgWidth, &imgHeight, &numColCh, STBI_rgb_alpha);

	if (imgWidth < 0) {
		std::cout << "Failed to load texture " << image << std::endl;
	}

	glGenTextures(1, &ID);
	glActiveTexture(slot);
	glBindTexture(texType, ID);

	glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// configure texture repeating
	glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(texType, 0, GL_RGBA, imgWidth, imgHeight, 0, format, pixelType, bytes);

	glGenerateMipmap(texType);

	stbi_image_free(bytes);

	// unbind
	glBindTexture(texType, 0);
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

void Texture::assignUnit(Shader& shader, const char* uniform, GLuint unit)
{
	shader.activate();
	glUniform1i(glGetUniformLocation(shader.ID, uniform), unit);
}

void Texture::bind()
{
	glBindTexture(type, ID);
}

void Texture::unbind()
{
	glBindTexture(type, 0);
}