#ifndef SCENE_H
#define SCENE_H
#include "iostream"
#include <SFML/Graphics.hpp>
using namespace sf;
#define ITEMS_BACKGROUND 3

class Game; //Declaracion anticipada de la clase Game

class Scene {
private:
	Game* game;
public:
	Scene(Game& game);
	virtual void update()=0;
	virtual void draw() = 0;
	Game *getInstanceGame();
};

#endif // !SCENE_H