#ifndef DRAGON_H
#define DRAGON_H
#include "../Character.h"

class Dragon : public Character {
public:
	Dragon();
	Dragon(int hp, int af, int am, int df, int dm, int vel);
	void attack() override;
	void defend() override;
};

#endif // !DRAGON_H

