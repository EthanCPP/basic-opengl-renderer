#include "Window.h"

Window::Window(unsigned int width, unsigned int height, const char* title)
{
	this->width = width;
	this->height = height;

	glfwInit();

	// OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindow = glfwCreateWindow(width, height, title, NULL, NULL);

	if (glfwWindow == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		throw 1;
	}

	glfwMakeContextCurrent(glfwWindow);

	gladLoadGL();

	glViewport(0, 0, width, height);
}

Window::~Window()
{
	glfwDestroyWindow(glfwWindow);
	glfwTerminate();
}
