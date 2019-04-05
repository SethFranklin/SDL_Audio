
#pragma once

#include <vector>

#include "shader.h"
#include "glad/glad.h"

class Model
{

public:

	Model(std::vector<float> Vertices);
	~Model();

	void UpdateGeometry(std::vector<float> Verticies);
	void Render(Shader s);

private:

	GLuint VBO;
	GLuint VAO;
	GLsizei VCount;

};
