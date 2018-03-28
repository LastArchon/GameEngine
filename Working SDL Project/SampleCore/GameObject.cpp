#include "stdafx.h"
#include "GameObject.h"
#include "deps\include\SDL\SDL.h"
#include <stdio.h>

namespace scene
{
	GameObject::GameObject()
	{

	}
	GameObject::~GameObject()
	{
	}
	bool GameObject::init()
	{
		Image = SDL_LoadBMP("Image.BMP");
		if (Image == NULL) {
			printf("Unable to load image %s! SDL Error: %s\n", "Image.BMP", SDL_GetError());
			return false;
		}
		return true; 
	}
	void GameObject::update()
	{
	}
	void GameObject::draw() const
	{
		
	}
	bool GameObject::shutdown()
	{
		return true;
	}
}


