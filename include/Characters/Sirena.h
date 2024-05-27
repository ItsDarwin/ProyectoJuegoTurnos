#ifndef SIRENA_H
#define SIRENA_H
#include "../Character.h"

class Sirena : public Character {
public:
	Sirena();
	Sirena(int hp, int af, int am, int df, int dm, int vel);
	void attack() override;
	void defend() override;
};

#endif // !SIRENA_H

