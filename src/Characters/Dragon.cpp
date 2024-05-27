#include "../../include/Characters/Dragon.h"

Dragon::Dragon():Character(){
	Character::setHP(static_cast<int>(600 * 0.27));
	Character::setAF(static_cast<int>(600 * 0.1));
	Character::setAM(static_cast<int>(600 * 0.26));
	Character::setDF(static_cast<int>(600 * 0.16));
	Character::setDM(static_cast<int>(600 * 0.1));
	Character::setVEL(static_cast<int>(600 * 0.11));
	Character::adjustStats(); //Variacion de las estadisticas

	if (!texture.loadFromFile("assets/sceneMenu/DragonP.png")) {
		std::cout << "Error loading texture from " << "assets/sceneMenu/DragonP.png" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, 0.0f);
}

Dragon::Dragon(int hp, int af, int am, int df, int dm, int vel) :Character() {
	Character::setHP(hp);
	Character::setAF(af);
	Character::setAM(am);
	Character::setDF(df);
	Character::setDM(dm);
	Character::setVEL(vel);

	if (!texture.loadFromFile("assets/sceneMenu/DragonP.png")) {
		std::cout << "Error loading texture from " << "assets/sceneMenu/DragonP.png" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, 0.0f);
}

void Dragon::attack() {
	//Logica para atacar
}

void Dragon::defend() {
	//Logica para defender
}