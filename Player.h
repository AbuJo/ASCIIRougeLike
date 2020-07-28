#pragma once
class Player
{

public:
	Player();

	void init(int level, int health, int attack, int defence, int experience);

	//setters
	void setPosition(int x, int y);
	void setHealth(int healthMod);
	void addHealthPot(int n);
	void setExperience(int experience);

	//getters
	void getPosition(int& x, int& y);
	int getHealth();
	int getAttack();
	int getDefence();
	int getHealthPots();

private:
	//properties
	int _level;
	int _health;
	int _attack;
	int _defence;
	int _experience;
	int _healthpots;

	//position
	int _x;
	int _y;

};

