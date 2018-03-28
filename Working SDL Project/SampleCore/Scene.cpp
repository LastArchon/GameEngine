#include "stdafx.h"
#include "Scene.h"
#include "GameObject.h"

namespace scene
{
	Scene::Scene()
	{
	}


	Scene::~Scene()
	{
	}

	bool Scene::init()
	{
		for (GameObject* g : gameObject)
		{
			if (!g->init())
			{
				return false;
			}
		}
		return true;
	}
	void Scene::update()
	{
		for (GameObject* g : gameObject)
		{
			g->update();
		}
	}
	void Scene::draw() const
	{
		for (GameObject* g : gameObject)
		{
			g->draw();
		}
	}
	bool Scene::shutdown()
	{
		for (GameObject* g : gameObject)
		{
			if (!g->shutdown())
			{
				return false;
			}
			delete g;
			g = nullptr;
		}

		gameObject.clear();
		return true;
	}
}
