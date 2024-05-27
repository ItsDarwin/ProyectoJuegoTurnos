#include "../include/Character.h"

Character::Character() {
	this->Stats[Stats::HP] = 0;
	this->Stats[Stats::ATK_F] = 0;
	this->Stats[Stats::ATK_M] = 0;
	this->Stats[Stats::DEF_F] = 0;
	this->Stats[Stats::DEF_M] = 0;
	this->Stats[Stats::VEL] = 0;
}

void Character::adjustStats() {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(-10, 10);

	for (size_t i = 0; i < MAX_STATS; i++) {
		enum Stats state = static_cast<enum Stats>(i);
		int variation = distrib(gen);
		Stats[state] = Stats[state] + (Stats[state] * variation / 100);
	}
}

const char* Character::statToString(enum Stats stat)const {
	switch (stat) {
		case HP: return "HP";
		case ATK_F: return "ATK_F";
		case ATK_M: return "ATK_M";
		case DEF_F: return "DEF_F";
		case DEF_M: return "DEF_M";
		case VEL: return "VEL";
		default: return "Unknown";
	}
}

int Character::getHP() {
	return this->Stats[Stats::HP];
}

int Character::getAF() {
	return this->Stats[Stats::ATK_F];
}

int Character::getAM() {
	return this->Stats[Stats::ATK_M];
}

int Character::getDF() {
	return this->Stats[Stats::DEF_F];
}

int Character::getDM() {
	return this->Stats[Stats::DEF_M];
}

int Character::getVEL() {
	return this->Stats[Stats::VEL];
}

void Character::setHP(int hp) {
	this->Stats[HP] = hp;
}
void Character::setAF(int af) {
	this->Stats[ATK_F] = af;
}
void Character::setAM(int am) {
	this->Stats[ATK_M] = am;
}
void Character::setDF(int df) {
	this->Stats[DEF_F] = df;
}
void Character::setDM(int dm) {
	this->Stats[DEF_M] = dm;
}
void Character::setVEL(int vel) {
	this->Stats[VEL] = vel;
}

sf::Sprite& Character::getSprite() {
	return sprite;
}

std::string Character::ProccessSendStats() {
	// Structure message = HP:AF:AM:DF:DM:VEL
	std::string sendStats = "";
	sendStats += std::to_string(Stats[HP]) + ":";
	sendStats += std::to_string(Stats[ATK_F]) + ":";
	sendStats += std::to_string(Stats[ATK_M]) + ":";
	sendStats += std::to_string(Stats[DEF_F]) + ":";
	sendStats += std::to_string(Stats[DEF_M]) + ":";
	sendStats += std::to_string(Stats[VEL]) + ":";
	return sendStats;
}