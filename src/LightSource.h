#pragma once
#include <glm/glm.hpp>

#include "Mesh.h"

class LightSource
{
public:
	LightSource();
	~LightSource();

	Mesh* mesh;
	glm::vec4 color;
private:
};

