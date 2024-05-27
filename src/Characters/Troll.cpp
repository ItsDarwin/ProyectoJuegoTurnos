#include "../../include/Characters/Troll.h"

Troll::Troll() :Character() {
	Character::setHP(static_cast<int>(600 * 0.27));
	Character::setAF(static_cast<int>(600 * 0.26));
	Character::setAM(static_cast<int>(600 * 0.11));
	Character::setDF(static_cast<int>(600 * 0.16));
	Character::setDM(static_cast<int>(600 * 0.1));
	Character::setVEL(static_cast<int>(600 * 0.1));
	Character::adjustStats(); //Variacion de las estadisticas
}

Troll::Troll(int hp, int af, int am, int df, int dm, int vel) :Character() {
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

void Troll::attack() {
	//Logica para atacar
}

void Troll::defend() {
	//Logica para defender
}
