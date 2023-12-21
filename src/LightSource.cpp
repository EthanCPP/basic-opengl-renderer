#include "LightSource.h"

LightSource::LightSource()
{
	// default to white light
	color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);

	std::vector<Vertex> vertices;

	vertices.push_back(Vertex{ glm::vec3(-0.1f, -0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.1f, -0.1f,  -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.1f, -0.1f, -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.1f, -0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.1f,  0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.1f,  0.1f, -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.1f,  0.1f, -0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.1f,  0.1f,  0.1f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f) });

	// Indices for vertices order
	std::vector<GLuint> indices;
	indices.insert(indices.end(), {
		0, 1, 2,
		0, 2, 3,
		0, 4, 7,
		0, 7, 3,
		3, 7, 6,
		3, 6, 2,
		2, 6, 5,
		2, 5, 1,
		1, 5, 4,
		1, 4, 0,
		4, 5, 6,
		4, 6, 7,
	});

	mesh = new Mesh(vertices, indices, MeshType::LIGHT);
	mesh->setTexturePath("src/textures/pop_cat.png");
}

LightSource::~LightSource()
{

}