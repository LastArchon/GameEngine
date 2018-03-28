#pragma once
#include <vector>
namespace scene
{
	class Scene
	{
	private:
		std::vector<class GameObject*> gameObject;
	public:
		Scene();
		virtual ~Scene();

		virtual bool init();
		virtual void update();
		virtual void draw() const;
		virtual bool shutdown();
	};
}


