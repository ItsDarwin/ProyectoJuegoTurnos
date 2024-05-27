#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

class Character {
private:
	enum Stats {
		HP,
		ATK_F,
		ATK_M,
		DEF_F,
		DEF_M,
		VEL,
		MAX_STATS
	};
	int Stats[MAX_STATS];
public:
	Character();
	void adjustStats();
	int getVEL();
	int getHP();
	int getAF();
	int getDF();
	int getAM();
	int getDM();
	void setHP(int hp);
	void setAF(int af);
	void setAM(int am);
	void setDF(int df);
	void setDM(int dm);
	void setVEL(int vel);
	const char* statToString(enum Stats stat)const;
	virtual void attack() = 0;
	virtual void defend() = 0;
	sf::Sprite& getSprite();
	std::string ProccessSendStats();
protected:
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif // !CHARACTER_H