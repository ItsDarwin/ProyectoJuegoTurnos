#include "../include/SceneBattle.h"
#include "../include/Game.h"

SceneBattle::SceneBattle(Game& game) : Scene(game) {
	//Fondo del menu
	if (!texture_background.loadFromFile("assets/sceneBattle/fondoBattle.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/sceneBattle/fondoBattle.png" << std::endl;
	}


	//Cargar en el sprite
	spriteBackground.setTexture(texture_background);

	for (size_t i = 0; i < MOVEMENTS; i++) {
		movements[i].setFont(getInstanceGame()->getFont());
		movements[i].setFillColor(Color::White);
		movements[i].setCharacterSize(30);
		movements[i].setOrigin(movements[i].getGlobalBounds().width / 2.0f, movements[i].getGlobalBounds().height / 2.0f);
		if (i == 0) {
			movements[i].setString("AtkPhy");
		}else if (i == 1) {
			movements[i].setString("AtkMag");
		}
		else if (i == 2) {
			movements[i].setString("DefPhy");
		}
		else if (i == 3) {
			movements[i].setString("DefMag");
		}
		movements[i].setPosition(getInstanceGame()->getWindow().getSize().x / 7.0f + (movements[i].getGlobalBounds().width * 2.0f) * i, getInstanceGame()->getWindow().getSize().y - movements[i].getCharacterSize() * 2.0f);
	}

	//Jugador
	getInstanceGame()->getCharacter(0)->getSprite().setPosition(getInstanceGame()->getWindow().getSize().x / 4.0f, getInstanceGame()->getWindow().getSize().y / 2.0f - getInstanceGame()->getCharacter(0)->getSprite().getGlobalBounds().height / 2.0f);
	//getInstanceGame()->getCharacter(0)->getSprite().setPosition(getInstanceGame()->getWindow().getSize().x / 4.0f, 640.0f - getInstanceGame()->getCharacter(0)->getSprite().getGlobalBounds().height);

	//Enemy
	getInstanceGame()->getCharacter(1)->getSprite().setScale(-1.f, 1.f);
	getInstanceGame()->getCharacter(1)->getSprite().setPosition(getInstanceGame()->getWindow().getSize().x / 4.0f * 3.0f, getInstanceGame()->getWindow().getSize().y / 2.0f - getInstanceGame()->getCharacter(0)->getSprite().getGlobalBounds().height / 2.0f);
}

void SceneBattle::update() {
	Vector2i mousePosition = Mouse::getPosition(getInstanceGame()->getWindow());

	for (size_t i = 0; i < MOVEMENTS; i++) {
		if (movements[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {
			movements[i].setFillColor(Color::Green);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (i == 0) {

				}
			}
		}
		else {
			movements[i].setFillColor(Color::White);
		}
	}
}

void SceneBattle::draw() {
	getInstanceGame()->getWindow().clear();
	//Dibuja el fondo del menu
	//getInstanceGame()->getWindow().draw(spriteBackground);
	for (size_t i = 0; i < ITEMS_BACKGROUND; i++) {//Dibuja el fondo del menu
		getInstanceGame()->getWindow().draw(getInstanceGame()->getSpritesFont(static_cast<int>(i)));
	}
	for (size_t i = 0; i < MOVEMENTS; i++) {
		getInstanceGame()->getWindow().draw(movements[i]);
	}

	getInstanceGame()->getWindow().draw(getInstanceGame()->getCharacter(0)->getSprite());
	getInstanceGame()->getWindow().draw(getInstanceGame()->getCharacter(1)->getSprite());
	getInstanceGame()->getWindow().display();
}