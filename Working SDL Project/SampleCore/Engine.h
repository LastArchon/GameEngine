#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H
#include "deps\include\SDL\SDL.h"
#include "InputSystem.h"
#include <vector>
#include "Manager.h"

#define ENGINE_INIT_ERROR      1
#define ENGINE_SHUTDOWN_ERROR  2


const int SCREEN_WIDTH = 620;
const int SCREEN_HEIGHT = 480;
namespace scene
{
	class Scene;
}
namespace Core
{
	class Engine
	{
	private:
		bool isRunning;
		std::vector<class Manager*> managers;
		scene::Scene* MainScene;

		//The window we'll be rendering to
		SDL_Window* window = NULL;

		//The surface contained by the window
		SDL_Surface* screenSurface = NULL;

		//Loads individual image
		//SDL_Surface* loadSurface = NULL;
		/*{
			//Load image at specified path
			SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
			if (loadedSurface == NULL)
			{
				printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}

			return loadedSurface;
		}  */

		InputSystem inputSystem;
	public:
		Engine(scene::Scene *s);
		~Engine();

		int init();
		int run();
	private:
		void update();
		void draw() const;
		int shutdown();
	};
}

#endif
