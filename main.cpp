
#include <SDL2/SDL.h>
#include <iostream>
#include <cstdint>
#include <chrono>

#include "glad/glad.h"
#include "main.h"
#include "input.h"
#include "shader.h"

SDL_Window* Window;
SDL_GLContext Context;

bool Running = true;
std::chrono::duration<double> StartupTime;

const uint32_t Window_Flags = SDL_WINDOW_OPENGL;
const unsigned int TargetFPS = 60;

int main()
{

	Main::Width = 640;
	Main::Height = 480;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{

		std::cout << "Couldn't initialize SDL: " << SDL_GetError() << std::endl;
		return 1;

	}

	Window = SDL_CreateWindow("Audio Demo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Main::Width, Main::Height, Window_Flags);

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
	
	Shader shad = Shader(std::string("simple"), (const Shader::Uniform[]) {Shader::Uniform::ROTATE}); 

	std::cout << "OpenGL Loaded. " << std::endl << "Vendor: " << glGetString(GL_VENDOR) << std::endl << "Renderer: " << glGetString(GL_RENDERER) << std::endl << "Version: " << glGetString(GL_VERSION) << std::endl;

	//glEnable(); depth test?

	glViewport(0, 0, Main::Width, Main::Height);

	auto StartupTime = std::chrono::high_resolution_clock::now();
	auto LastFrame = StartupTime;

	std::chrono::duration<double> TargetFrameTime = std::chrono::nanoseconds(long(1000000000) / long(TargetFPS));

	while (Running)
	{

		auto CurrentFrame = std::chrono::high_resolution_clock::now();

		auto dt = CurrentFrame - LastFrame;

		if (dt >= TargetFrameTime)
		{

			LastFrame = CurrentFrame;

			Main::DeltaTime = dt.count() / 1000000000.0;
			Main::TimeSinceStart = (CurrentFrame - StartupTime).count() / 1000000000.0;

			// Events

			SDL_Event Event;

			while (SDL_PollEvent(&Event))
			{

				switch (Event.type)
				{

					case SDL_WINDOWEVENT:
						switch (Event.window.event)
						{

							case SDL_WINDOWEVENT_CLOSE:
								Main::Close();
								break;

						}
					break;
					case SDL_KEYDOWN:
						if (Event.key.keysym.sym < 128) Input::SetState(Event.key.keysym.sym, true);
					break;
					case SDL_KEYUP:
						if (Event.key.keysym.sym < 128) Input::SetState(Event.key.keysym.sym, false);
					break;

				}

			}

			// Update
			
			// Push back inputs

			Input::PushBackInputs();

			// Render

			double Amp = (sin(Main::TimeSinceStart) + 1.0) * 0.5;
			glClearColor(Amp, Amp, Amp, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);

			SDL_GL_SwapWindow(Window);

		}

	}
	
	SDL_GL_DeleteContext(Context);
	SDL_DestroyWindow(Window);
	SDL_Quit();

	return 0;

}

void Main::Close()
{

	Running = false;

}
