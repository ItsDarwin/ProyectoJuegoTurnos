#ifndef TROLL_H
#define TROLL_H
#include "../Character.h"

class Troll : public Character {
public:
	Troll();
	Troll(int hp, int af, int am, int df, int dm, int vel);
	void attack() override;
	void defend() override;
private:
	sf::Texture textures;
	sf::Sprite sprite;
};

#endif // !