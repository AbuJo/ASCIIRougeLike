#include "Monster.h"

Monster::Monster() {
	_x = 0;
	_y = 0;
	_attack = 0;
	_defence = 0;
	_health = 0;
}

void Monster::init( int health, int attack, int defence) {
	_health = health;
	_attack = attack;
	_defence = defence;
}

//setters
void Monster::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

void Monster::setHealth(int healthMod) {
	_health += healthMod;
}

//getters
int Monster::getHealth() {
	return _health;
}