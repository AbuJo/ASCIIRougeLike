#include "Player.h"
#include <iostream>

Player::Player() {
	_x = 0;
	_y = 0;
	_attack = 0;
	_defence = 0;
	_level = 0;
	_experience = 0;
	_health = 0;
}

void Player::init(int level, int health, int attack, int defence, int experience) {
	_level = level;
	_health = health;
	_attack = attack;
	_defence = defence;
	_experience = experience;
}

//setters
void Player::setPosition(int x, int y) {
	_x = x;
	_y = y;
}

//getters

void Player::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}