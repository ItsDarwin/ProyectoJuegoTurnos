#include "../include/SceneSelectPlayer.h"
#include "../include/Game.h"

SceneSelectPlayer::SceneSelectPlayer(Game &game):Scene(game),selectIndex(-1) {
	tileScene.setFont(game.getFont());
	tileScene.setFillColor(Color::White);
	tileScene.setString("Select your rol");
	tileScene.setCharacterSize(80);
	tileScene.setPosition(game.getWindow().getSize().x / 2.0f - (tileScene.getGlobalBounds().width / 2.0f), 0.0f);

	backScene.setFont(game.getFont());
	backScene.setFillColor(Color::White);
	backScene.setString("Back");
	backScene.setCharacterSize(40);
	backScene.setPosition(game.getWindow().getSize().x / 2.0f - (backScene.getGlobalBounds().width / 2.0f), game.getWindow().getSize().y - static_cast<float>(backScene.getCharacterSize()) * 2.0f);

	stat.setFont(game.getFont());
	stat.setFillColor(Color::White);
	stat.setString("Stats");
	stat.setCharacterSize(40);
	stat.setPosition(((game.getWindow().getSize().x / 2.0f) )- (stat.getGlobalBounds().width), game.getWindow().getSize().y / 2.0f);

	for (size_t i = 0; i < 6; i++) {
		stats[i].setFont(game.getFont());
		stats[i].setFillColor(Color::White);
		stats[i].setString("None");
		stats[i].setCharacterSize(30);
		if (i > 2) {
			stats[i].setPosition(game.getWindow().getSize().x / 2.0f + stats[i].getGlobalBounds().width / 2.0f + stats->getCharacterSize() * 6, game.getWindow().getSize().y / 2.0f + 50 * (i - 2));
		}
		else {
			stats[i].setPosition(game.getWindow().getSize().x / 2.0f - stats[i].getGlobalBounds().width, game.getWindow().getSize().y / 2.0f + 50 * (i + 1));
		}
		
	}
	
	for (size_t i = 0; i < OPTIONS_SELECT_SCENE; i++) {
		selectedPlayer[i].setFont(game.getFont());
		selectedPlayer[i].setFillColor(Color::White);
		if (i == 0) {
			selectedPlayer[i].setString("Dragon");
		}else if (i == 1) {
			selectedPlayer[i].setString("Sirena");
		}else if (i == 2) {
			selectedPlayer[i].setString("Troll");
		}else if (i == 3) {
			selectedPlayer[i].setString("Yordle");
		}
		selectedPlayer[i].setCharacterSize(60);
		selectedPlayer[i].setOrigin(selectedPlayer[i].getGlobalBounds().getSize().x / 2.0f, selectedPlayer[i].getGlobalBounds().getSize().y / 2.0f);
		selectedPlayer[i].setPosition(game.getWindow().getSize().x / 4.0f, game.getWindow().getSize().y / 4.0f + 100 * i);
	}

	frameRects[0] = { 0, 0, 256, 190 };
	frameRects[1] = { 0,0,96,126 };
	frameRects[2] = {0,0,130,250};
	frameRects[3] = {0,0,90,125};

	//Cargar spritesheets
	if (!rolesTextures[0].loadFromFile("assets/sceneMenu/dragonQuiet.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/sceneMenu/dragonQuiet.png" << std::endl;
	}
	if (!rolesTextures[1].loadFromFile("assets/sceneMenu/sirenaQuiet.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/sceneMenu/sirenaQuiet.png" << std::endl;
	}
	if (!rolesTextures[2].loadFromFile("assets/sceneMenu/trollQuiet.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/sceneMenu/trollQuiet.png" << std::endl;
	}
	if (!rolesTextures[3].loadFromFile("assets/sceneMenu/yordleQuiet.png")) {
		std::cout << "ERROR : No se encontro la textura" << "assets/sceneMenu/yordleQuiet.png" << std::endl;
	}

	for (size_t i = 0; i < OPTIONS_SELECT_SCENE; i++) {
		rolesSelect[i].setTexture(rolesTextures[i]);
	}
	//Posicionar
	for (size_t i = 0; i < OPTIONS_SELECT_SCENE; i++) {
		rolesSelect[i].setPosition(((game.getWindow().getSize().x / 4.0f) * 3.0f) - rolesSelect[i].getGlobalBounds().width / 10.0f, (game.getWindow().getSize().y / 2.0f) - rolesSelect[i].getGlobalBounds().height);
	}
	
}

void SceneSelectPlayer::update() {
	Vector2i mousePosition = Mouse::getPosition(getInstanceGame()->getWindow());
	bool hovering = false; //Variable para saber si se esta encima de una raza

	for (size_t i = 0; i < OPTIONS_SELECT_SCENE; i++) {
		if (selectedPlayer[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {
			selectedPlayer[i].setFillColor(Color::Green);
			selectIndex = static_cast<int>(i);
			hovering = true;
			if (i == 0) {
				stats[0].setString("HP:324");
				stats[1].setString("ATK FS:60");
				stats[2].setString("DEF FS:96");
				stats[3].setString("ATK MG:156");
				stats[4].setString("DEF MG:60");
				stats[5].setString("VEL:66");
				if (Mouse::isButtonPressed(Mouse::Left)) {
					std::cout << "Seleccionaste Dragon" << std::endl;
					getInstanceGame()->changeScene(new SceneWaiting(*getInstanceGame(),selectedPlayer[i].getString()));
				}
			}
			else if (i == 1) {
				stats[0].setString("HP:120");
				stats[1].setString("ATK FS:96");
				stats[2].setString("DEF FS:60");
				stats[3].setString("ATK MG:66");
				stats[4].setString("DEF MG:162");
				stats[5].setString("VEL:156");
				if (Mouse::isButtonPressed(Mouse::Left)) {
					std::cout << "Seleccionaste Sirena" << std::endl;
					getInstanceGame()->changeScene(new SceneWaiting(*getInstanceGame(), selectedPlayer[i].getString()));
				}
			}
			else if (i == 2) {
				stats[0].setString("HP:324");
				stats[1].setString("ATK FS:156");
				stats[2].setString("DEF FS:96");
				stats[3].setString("ATK MG:66");
				stats[4].setString("DEF MG:60");
				stats[5].setString("VEL:60");
				if (Mouse::isButtonPressed(Mouse::Left)) {
					std::cout << "Seleccionaste Troll" << std::endl;
					getInstanceGame()->changeScene(new SceneWaiting(*getInstanceGame(), selectedPlayer[i].getString()));
				}
			}
			else if (i == 3) {
				stats[0].setString("HP:120");
				stats[1].setString("ATK FS:60");
				stats[2].setString("DEF FS:66");
				stats[3].setString("ATK MG:156");
				stats[4].setString("DEF MG:96");
				stats[5].setString("VEL:162");
				if (Mouse::isButtonPressed(Mouse::Left)) {
					std::cout << "Seleccionaste Yordle" << std::endl;
					getInstanceGame()->changeScene(new SceneWaiting(*getInstanceGame(), selectedPlayer[i].getString()));
				}
			}
		}
		else {
			selectedPlayer[i].setFillColor(Color::White);
		}
	}
	if (!hovering) {
		selectIndex = -1;
	}
	if (backScene.getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {
		backScene.setFillColor(Color::Green);
		if (Mouse::isButtonPressed(Mouse::Left)) {
			getInstanceGame()->changeScene(new SceneMenu(*getInstanceGame()));
		}
	}
	else {
		backScene.setFillColor(Color::White);
	}
}

void SceneSelectPlayer::draw() {
	getInstanceGame()->getWindow().clear();
	for (size_t i = 0; i < 3; i++) {//Dibuja el fondo del menu
		getInstanceGame()->getWindow().draw(getInstanceGame()->getSpritesFont(static_cast<int>(i)));
	}

	getInstanceGame()->getWindow().draw(tileScene);
	for (size_t i = 0; i < 4; i++) { //Dibuja las opciones del menu
		getInstanceGame()->getWindow().draw(selectedPlayer[i]);
	}
	getInstanceGame()->getWindow().draw(backScene);
	if (selectIndex != -1) {
		if (clockFrame.getElapsedTime().asSeconds() > 1.0f / 10.0f) {
			frameRects[selectIndex].left += frameRects[selectIndex].width;
			if (static_cast<unsigned int>(frameRects[selectIndex].left + frameRects[selectIndex].width) > rolesTextures[selectIndex].getSize().x) {
				frameRects[selectIndex].left = 0;
			}
			rolesSelect[selectIndex].setTextureRect(frameRects[selectIndex]);
			clockFrame.restart();
		}
		getInstanceGame()->getWindow().draw(rolesSelect[selectIndex]);
		getInstanceGame()->getWindow().draw(stat);
		for (size_t i = 0; i < 6; i++) {
			getInstanceGame()->getWindow().draw(stats[i]);
		}
	}
	getInstanceGame()->getWindow().display();
}
