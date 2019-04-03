
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdint>

#include "glad/glad.h"

unsigned int Width = 640;
unsigned int Height = 480;

SDL_Window* Window;
SDL_GLContext Context;

const uint32_t Window_Flags = SDL_WINDOW_OPENGL;

int main()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{

		std::cout << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
		return 1;

	}

	Window = SDL_CreateWindow("Audio Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, Window_Flags);

	if (Window == NULL)
	{

		std::cout << "Couldn't create a window: " << SDL_GetError() << std::endl;
		return 1;

	}

	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	Context = SDL_GL_CreateContext(Window);
	
	if (Context == NULL)
	{

		std::cout << "Couldn't create OpenGL Context: " << SDL_GetError() << std::endl;
		return 1;

	}

	gladLoadGLLoader(SDL_GL_GetProcAddress);

	std::cout << "OpenGL Loaded. " << std::endl << "Vendor: " << glGetString(GL_VENDOR) << std::endl << "Renderer: " << glGetString(GL_RENDERER) << std::endl << "Version: " << glGetString(GL_VERSION) << std::endl;

	//glEnable();

	glViewport(0, 0, Width, Height);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	SDL_GL_SwapWindow(Window);

	SDL_Delay(5000);

	SDL_GL_DeleteContext(Context);
	SDL_DestroyWindow(Window);
	SDL_Quit();

	return 0;

}
