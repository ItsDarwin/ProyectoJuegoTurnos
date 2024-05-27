#include "../include/Scene.h"
#include "../include/Game.h"

Scene::Scene(Game& game):game(&game) {
}

Game* Scene::getInstanceGame() {
	return this->game;
}