
#include <string>
#include <vector>
#include <fstream>
#include <streambuf>
#include <iostream>

#include "shader.h"
#include "glad/glad.h"

Shader::Shader(std::string Name, const Uniform Uniforms[])
{

	std::ifstream stream("glsl/" + Name + ".vert");
	std::string string1((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());
	stream.close();
	stream.open("glsl/" + Name + ".frag");
	std::string string2((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

	std::cout << string1 << std::endl << string2 << std::endl;

	//GLuint Vertex = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(Vertex, 1, string1.c_st(), NULL);
	//glCompileShader(Vertex);

}

Shader::~Shader()
{

	glDeleteProgram(Program);

}

void Shader::Use()
{

	glUseProgram(Program);

}

void Shader::SetUniform(Shader::Uniform u, float a)
{

	glUniform1f(Locations[u], a);

}

void Shader::SetUniform(Shader::Uniform u, int a)
{

	glUniform1i(Locations[u], a);

}

