
#pragma once 

#include <string>
#include <vector>

#include "glad/glad.h"

class Shader
{

public:

	enum Uniform
	{

		TRANSLATE,
		ROTATE,
		SCALE,
		TRANSPARENCY,
		ALPHA,
		TEXTURE,
		DIFFUSE,
		NORMAL,
		SPECULAR,
		DEPTH,
		LIGHT,
		COLOR,
		TIME,
		ENUM_MAX

	};

	Shader(std::string Name, const Uniform Uniforms[]);
	~Shader();

	void Use();
	
	void SetUniform(Uniform u, float a);
	void SetUniform(Uniform u, int a);

	// More uniform types for vector and matrix classes

private:

	GLuint Program;
	GLint Locations[Shader::Uniform::ENUM_MAX];

};
