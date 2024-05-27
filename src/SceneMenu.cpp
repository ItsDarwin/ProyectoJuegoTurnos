#include "..//include/SceneMenu.h"
#include "..//include/Game.h"

SceneMenu::SceneMenu(Game& game):Scene(game) {
	for (size_t i = 0; i < OPTIONS_MENU; i++) {
		menu[i].setFont(game.getFont());
		menu[i].setFillColor(Color::White);
		if (i == 0) {
			menu[0].setString("Play");
		}
		else if (i == 1) {
			menu[1].setString("Exit");
		}
		menu[i].setCharacterSize(60);
		menu[i].setPosition(game.getWindow().getSize().x / 2.0f - static_cast<float>(menu[0].getCharacterSize()), game.getWindow().getSize().y / static_cast<float>(2) + 100 * i);
	}
}

void SceneMenu::draw() { //Dibuja cada elemento del menu
	getInstanceGame()->getWindow().clear();
	for (size_t i = 0; i < ITEMS_BACKGROUND; i++) {//Dibuja el fondo del menu
		getInstanceGame()->getWindow().draw(getInstanceGame()->getSpritesFont(static_cast<int>(i)));
	}

	for (size_t i = 0; i < OPTIONS_MENU; i++) { //Dibuja las opciones del menu
		getInstanceGame()->getWindow().draw(menu[i]);
	}
	getInstanceGame()->getWindow().display();
}

void SceneMenu::update() {
	Vector2i mousePosition = Mouse::getPosition(getInstanceGame()->getWindow());
	
	for (size_t i = 0; i < OPTIONS_MENU; i++) {
		if (menu[i].getGlobalBounds().contains(static_cast<Vector2f>(mousePosition))) {
			menu[i].setFillColor(Color::Green);
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (i == 0) {
					std::cout << "Play game" << std::endl;
					getInstanceGame()->changeScene(new SceneSelectPlayer(*getInstanceGame()));
				}
				else if (i == 1) {
					getInstanceGame()->getWindow().close();
				}
			}
		}
		else{
			menu[i].setFillColor(Color::White);
		}
	}
}

