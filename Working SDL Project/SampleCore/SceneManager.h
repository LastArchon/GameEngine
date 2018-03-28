#pragma once
#include <vector>
namespace scene
{
	class SceneManager
	{

	private:
		std::vector<class Scene*> Scenes;
		SceneManager();
		static SceneManager* sm_instance;
	public:
		~SceneManager();
		bool init();
		void update();
		void draw() const;
		bool shutdown();

		static SceneManager* getInstance()
		{
			if (sm_instance == NULL)
			{
				sm_instance = new SceneManager();
			}
			return sm_instance;
		}

	};
}

