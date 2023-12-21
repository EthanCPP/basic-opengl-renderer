#pragma once
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(std::string filename);

class Shader
{
public:
	Shader(std::string vertexFile, std::string fragmentFile);
	~Shader();

	void activate();

	GLuint ID;
private:
	void compileErrors(unsigned int shader, const char* type);
};

