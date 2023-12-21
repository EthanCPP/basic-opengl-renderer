#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window
{
public:
	Window(unsigned int width, unsigned int height, const char* title);
	~Window();

	GLFWwindow* glfwWindow;

	unsigned int width;
	unsigned int height;
};

