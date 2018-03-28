#include "stdafx.h"
#include "InputSystem.h"
#include "deps\include\SDL\SDL.h"

namespace Core
{
    InputSystem::InputSystem() : System(SystemType::INPUT), requestedQuit(false)
    {
    }
    
    
    InputSystem::~InputSystem()
    {
    }

	void InputSystem::update()
	{
		SDL_Event e;

		while (SDL_PollEvent(&e) != 0)
		{
			

			switch (e.type)
			{
			case (SDL_KEYDOWN):
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					printf("UP \n");
					e_upPressed = true;
					break;
				case SDLK_DOWN:
					printf("DOWN \n");
					e_downPressed = true;
					break;
				case SDLK_RIGHT:
					printf("RIGHT \n");
					e_rightPressed = true;
					break;
				case SDLK_LEFT:
					printf("LEFT \n");
					e_leftPressed = true;
					break;

				case SDLK_ESCAPE:
					requestedQuit = true;
					break;
				}
				//printf("You pressed something");
				break;
			case (SDL_KEYUP):
				switch (e.key.keysym.sym)
				{

				case SDLK_LEFT:
					e_leftPressed = false;
					printf("lwftrel \n");
					break;
				case SDLK_UP:
					printf("UP rel \n");
					e_upPressed = false;
					break;
				case SDLK_DOWN:
					printf("DOWNrel \n");
					e_downPressed = false;
					break;
				case SDLK_RIGHT:
					printf("RIGHTrel \n");
					e_rightPressed = false;
					break;
				}
			default:
				break;
			}

		}
	}

}
