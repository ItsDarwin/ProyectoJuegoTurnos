#ifndef SCENE_WAITING
#define SCENE_WAITING
#include "Scene.h"

class SceneWaiting : public Scene {
public:
	SceneWaiting(Game& game,std::string rol);
	void update()override;
	void draw()override;
private:
	Text waitingText;
	int dotCount;
	Clock clock;
	std::string rol;
	std::string rolEnemy;
	bool sendRol;
};

#endif // !SCENE_WAITING
