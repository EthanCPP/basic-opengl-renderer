#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>

#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Shader.h"
#include "Texture.h"

enum class MeshType {
	STATIC,
	LIGHT,
};

class Mesh
{
public:
	Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, MeshType meshType);
	Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
	~Mesh();

	void setTexturePath(std::string texturePath);
	void prepareTexture(Shader& shader);

	void rotate(float amount, glm::vec3 axis);
	void translate(glm::vec3 position);
	void draw(Shader& shader);
	
	glm::vec3 getPosition();

	VAO VAO;
	MeshType meshType;
private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	std::string texturePath;
	Texture* texture;

	glm::mat4 model;
private:
	glm::vec3 modelScale;
	glm::quat modelRotation;
	glm::vec3 modelTranslation;
	glm::vec3 modelSkew;
	glm::vec4 modelPerspective;

	void decompose();
};

