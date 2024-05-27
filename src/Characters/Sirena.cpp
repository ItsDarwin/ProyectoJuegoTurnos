#include "../../include/Characters/Sirena.h"

Sirena::Sirena() :Character() {
	Character::setHP(static_cast<int>(600 * 0.1));
	Character::setAF(static_cast<int>(600 * 0.16));
	Character::setAM(static_cast<int>(600 * 0.11));
	Character::setDF(static_cast<int>(600 * 0.1));
	Character::setDM(static_cast<int>(600 * 0.27));
	Character::setVEL(static_cast<int>(600 * 0.26));
	Character::adjustStats(); //Variacion de las estadisticas

	if (!texture.loadFromFile("assets/sceneMenu/SirenaP.png")) {
		std::cout << "Error loading texture from " << "assets/sceneMenu/DragonP.png" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, 0.0f);
}

Sirena::Sirena(int hp, int af, int am, int df, int dm, int vel) :Character() {
	Character::setHP(hp);
	Character::setAF(af);
	Character::setAM(am);
	Character::setDF(df);
	Character::setDM(dm);
	Character::setVEL(vel);

	if (!texture.loadFromFile("assets/sceneMenu/SirenaP.png")) {
		std::cout << "Error loading texture from " << "assets/sceneMenu/SirenaP.png" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2.0f, 0.0f);
}

void Sirena::attack() {
	//Logica para atacar
}

void Sirena::defend() {
	//Logica para defender
}