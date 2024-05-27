#ifndef SCENEMENU_H
#define SCENEMENU_H
#include "Scene.h"
#define OPTIONS_MENU 2


class SceneMenu :
    public Scene
{
private:
    Text menu[OPTIONS_MENU];
public:
    SceneMenu(Game& game);
    void update()override;
    void draw()override;
};

#endif // !SCENEMENU_H