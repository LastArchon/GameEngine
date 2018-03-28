#include <Scene.h>

class MainScene : public scene::Scene
{
public:
	MainScene();
	~MainScene();
	bool init();
	void update() ;
	void draw() const;
	bool shutdown();
};
