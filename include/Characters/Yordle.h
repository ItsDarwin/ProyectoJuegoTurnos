#ifndef YORDLE_H
#define YORDLE_H
#include "../Character.h"

class Yordle : public Character {
public:
	Yordle();
	Yordle(int hp, int af, int am, int df, int dm, int vel);
	void attack() override;
	void defend() override;
private:
	sf::Texture textures;
	sf::Sprite sprite;
};

#endif // !YORDLE_H

