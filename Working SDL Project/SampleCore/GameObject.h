#pragma once
#include "deps\include\SDL\SDL.h"
namespace scene
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();
		bool init();
		void update();
		void draw() const;
		bool shutdown();

		//Loads individual image
		SDL_Surface* Image = NULL;
	};
}


