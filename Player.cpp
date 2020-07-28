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

void Player::setHealth(int healthMod) {
	_health += healthMod;
}

void Player::addHealthPot(int n) {
	_healthpots += n;
}

void Player::setExperience(int experience) {
	_experience += experience;
	if (_experience >= 100) {
		_experience -= 100;
		_level += 1;
		_attack += 1;
		_defence += 1;
		_health += 10;
	}
}

//getters
void Player::getPosition(int& x, int& y) {
	x = _x;
	y = _y;
}

int Player::getHealth() {
	return _health;
}

int Player::getAttack() {
	return _attack;
}

int Player::getDefence() {
	return _defence;
}

int Player::getHealthPots() {
	return _healthpots;
}