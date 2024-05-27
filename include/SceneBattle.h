#ifndef SCENE_BATTLE
#define SCENE_BATTLE
#include "Scene.h"
#define MOVEMENTS 4

class SceneBattle:public Scene{
private:
    Texture texture_background;
    Sprite spriteBackground;
    Text movements[MOVEMENTS];
public:
    SceneBattle(Game& game);
    void update()override;
    void draw()override;
};

#endif // !SCENE_BATTLE

