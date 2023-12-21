#include "Window.h"
#include "Renderer.h"

#include "LightSource.h"

int main()
{
	Window window(1920, 1080, "Basic OpenGL Renderer");

	Renderer renderer(&window);
	renderer.init();

	std::vector<Vertex> vertices;

	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.0f,  0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-0.8f, 0.5f,  0.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-0.8f, 0.5f,  0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.8f,  0.0f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-0.8f, 0.5f,  0.0f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.5f, -0.8f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.5f, -0.8f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.8f,  0.0f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.5f, -0.8f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.0f, -0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.8f, 0.5f,  0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.0f,  0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.8f, 0.5f,  0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.8f,  0.0f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.8f, 0.5f,  0.0f) });
	vertices.push_back(Vertex{ glm::vec3(0.5f, 0.0f,  0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.5f,  0.8f) });
	vertices.push_back(Vertex{ glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.5f,  0.8f) });
	vertices.push_back(Vertex{ glm::vec3(0.0f, 0.8f,  0.0f), glm::vec3(0.5f, 0.2f, 0.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.5f,  0.8f) });

	// Indices for vertices order
	std::vector<GLuint> indices;
	indices.insert(indices.end(), {
		0, 1, 2, // Bottom side
		0, 2, 3, // Bottom side
		4, 6, 5, // Left side
		7, 9, 8, // Non-facing side
		10, 12, 11, // Right side
		13, 15, 14 // Facing side
	});

	Mesh mesh1(vertices, indices);
	mesh1.rotate(45.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	renderer.addMesh(mesh1);

	LightSource lightSource;
	//lightSource.mesh->rotate(45.0f, glm::vec3(1.0f, 1.0f, 1.0f));
	lightSource.mesh->translate(glm::vec3(-1.0f, 0, 1.0f));
	//lightSource.color = glm::vec4(0.6f, 0.2f, 0.1f, 1.0f);

	renderer.addLightSource(lightSource);

	renderer.enterGameLoop();

	return 0;
}