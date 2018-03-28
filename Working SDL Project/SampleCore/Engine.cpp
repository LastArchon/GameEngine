#include "stdafx.h"
#include "Engine.h"
#include "Scene.h"
#include <iostream>
#include "deps\include\SDL\SDL.h"
#include "SystemManager.h"
#include "InputSystem.h"

namespace Core
{
	Engine::Engine(scene::Scene *s) : MainScene(s), isRunning(false)
	{
		managers.push_back(SystemManager::getInstance());
	}
	Engine::~Engine()
	{
	}
	int Engine::init()
	{
		int initResult = 0;


		//Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());

			initResult = ENGINE_INIT_ERROR;
		}
		else
		{
			//Create window
			window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());

				initResult = ENGINE_INIT_ERROR;
			}
			else
			{
				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);
			}

		}
		MainScene->init();
		return 0;
	}
	int Engine::run()
	{
		isRunning = true;

		//systemManager
		while (!inputSystem.QuitRequested())
		{
			//printf("do you work?");
			//update
			update();
			//render
			draw();
			

		}
		return shutdown();
	}
	void Engine::update()
	{
		MainScene->update();
		inputSystem.update();

		//Update the surface
		SDL_UpdateWindowSurface(window);


	}
	void Engine::draw() const
	{
		MainScene->draw();

		//Fill the surface purple
		//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 204, 0, 204));

		//Wait two seconds
		//SDL_Delay(10000);

	}
	int Engine::shutdown()
	{
		if (MainScene->shutdown())
		{
			return 1;
		}

		//Destroy window
		SDL_DestroyWindow(window);

		//Quit SDL subsystems
		SDL_Quit();
		return 0;
	}
}

