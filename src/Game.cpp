#include "../include/Game.h"
#include "../include/Scene.h"

Game::Game():window(VideoMode(1280,720),"Proyecto", Style::Close | Style::Titlebar),networkManager(*this),charactersExist(false) {
	window.setFramerateLimit(60);
	this->currentScene = new SceneMenu(*this);
	this->pendingScene = nullptr;
	if (!fontGame.loadFromFile("assets/menu/font/Retro-Gaming.ttf")) {
		std::cout << "ERROR : No se encontro la fuente" << "assets/menu/font/Retro-Gaming.ttf" << std::endl;
	}

	//Fondo
	if (!textures_background[0].loadFromFile("assets/menu/background/back1.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/menu/background/back1" << std::endl;
	}
	if (!textures_background[1].loadFromFile("assets/menu/background/back3.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/menu/background/back2" << std::endl;
	}
	if (!textures_background[2].loadFromFile("assets/menu/background/back2.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/menu/background/back3" << std::endl;
	}


	//Cargar en los sprites las texturas del fondo
	for (size_t i = 0; i < ITEMS_BACKGROUND; i++) {
		sprites[i].setTexture(textures_background[i]);
	}

}

void Game::initMyCharacter(std::string rolMy) {
	std::string roles[] = { "Dragon","Sirena","Troll","Yordle" };

	//Para el jugador local
	for (size_t i = 0; i < 4; i++) {
		if (rolMy == roles[i]) {
			if (i == 0) {
				characters[0] = new Dragon();
				std::cout << "Se creo un caracter de tipo dragon." << std::endl;
			}
			else if (i == 1) {
				characters[0] = new Sirena();
				std::cout << "Se creo un caracter de tipo sirena." << std::endl;
			}
			else if (i == 2) {
				characters[0] = new Troll();
				std::cout << "Se creo un caracter de tipo troll." << std::endl;
			}
			else if (i == 3) {
				characters[0] = new Yordle();
				std::cout << "Se creo un caracter de tipo yordle." << std::endl;
			}
		}
	}
}

void Game::initEnemyCharacter(std::string statsEnemy,std::string rolEnemy) {
	std::string temp = "";
	int count = 0;
	int stats[6] = { 0,0,0,0,0,0 };
	for (size_t i = 0; i < statsEnemy.size(); i++) {
		if (statsEnemy[i] == ':') {
			stats[count] = std::stoi(temp);
			count++;
			temp = "";
		}
		else {
			temp += statsEnemy[i];
		}
	}
	std::string roles[] = { "Dragon","Sirena","Troll","Yordle" };
	//Para el jugador externo
	for (size_t i = 0; i < 4; i++) {
		if (rolEnemy == roles[i]) {
			if (i == 0) {
				characters[1] = new Dragon(stats[0],stats[1],stats[2],stats[3],stats[4],stats[5]);
				std::cout << "Se creo un caracter de tipo dragon." << std::endl;
			}
			else if (i == 1) {
				characters[1] = new Sirena(stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);
				std::cout << "Se creo un caracter de tipo sirena." << std::endl;
			}
			else if (i == 2) {
				characters[1] = new Troll(stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);
				std::cout << "Se creo un caracter de tipo troll." << std::endl;
			}
			else if (i == 3) {
				characters[1] = new Yordle(stats[0], stats[1], stats[2], stats[3], stats[4], stats[5]);
				std::cout << "Se creo un caracter de tipo yordle." << std::endl;
			}
		}
	}
	charactersExist = true;
}

Game::~Game() {
	//Eliminar la escena actual al destruir el juego
	if (currentScene != nullptr) {
		delete currentScene;
	}
	if (pendingScene != nullptr) {
		delete pendingScene;
	}
	for (size_t i = 0; i < 2; i++) {
		delete characters[i];
	}
}

void Game::updateWindowEvents() {
	Event ev;
	while (window.pollEvent(ev)) {
		if (ev.type == Event::Closed) {
			window.close();
		}
		currentScene->update();
	}
}


void Game::render() {
	currentScene->draw();
}

void Game::changeScene(Scene* newScene) {
	pendingScene = newScene; //Establecer la escena pendiente
}

void Game::run() {
	while (window.isOpen()) {
		updateWindowEvents();
		processPendingScene();
		render();
	}
}

void Game::processPendingScene() {
	if (pendingScene != nullptr) {
		if (currentScene != nullptr) {
			delete currentScene;  // Eliminar la escena actual
		}
		currentScene = pendingScene;  // Establecer la nueva escena
		pendingScene = nullptr;  // Restablecer el puntero de escena pendiente
	}
}

NetworkManager* Game::getNetworkManager() {
	return &networkManager;
}

const Font& Game::getFont() const{
	return fontGame;
}

RenderWindow& Game::getWindow() {
	return window;
}

const Sprite& Game::getSpritesFont(int index) const {
	return sprites[index];
}

bool Game::getCharactersExist() const {
	return charactersExist;
}

Character* Game::getCharacter(int index) {
	return characters[index];
}
