#include "Mesh.h"
#include <iostream>

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, MeshType meshType)
{
	this->vertices = vertices;
	this->indices = indices;
	this->meshType = meshType;

	VAO.bind();

	VBO VBO(this->vertices);
	EBO EBO(this->indices);

	VAO.linkAttribute(VBO, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);					// position 
	VAO.linkAttribute(VBO, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float))); // color 
	VAO.linkAttribute(VBO, 2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float))); // texture uv map 
	VAO.linkAttribute(VBO, 3, 3, GL_FLOAT, sizeof(Vertex), (void*)(8 * sizeof(float))); // normals
	
	VAO.unbind();
	VBO.unbind();
	EBO.unbind();

	this->model = glm::mat4(1.0f);
}

Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices) :
	Mesh(vertices, indices, MeshType::STATIC)
{
}

Mesh::~Mesh()
{

}

void Mesh::setTexturePath(std::string texturePath)
{
	this->texturePath = texturePath;
}

void Mesh::prepareTexture(Shader& shader)
{
	if (!this->texturePath.empty()) {
		this->texture = new Texture(this->texturePath.c_str(), GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
		this->texture->assignUnit(shader, "tex0", 0);
	}
}

void Mesh::rotate(float amount, glm::vec3 axis)
{
	this->model = glm::rotate(this->model, glm::radians(amount), axis);
}

void Mesh::translate(glm::vec3 position)
{
	this->model = glm::translate(this->model, position);
}

void Mesh::draw(Shader& shader)
{
	shader.activate();

	if (texture != NULL) {
		texture->bind();
	}

	VAO.bind();

	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(this->model));

	// draw the mesh
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

glm::vec3 Mesh::getPosition()
{
	this->decompose();

	return modelTranslation;
}

void Mesh::decompose()
{
	glm::decompose(model, modelScale, modelRotation, modelTranslation, modelSkew, modelPerspective);
}