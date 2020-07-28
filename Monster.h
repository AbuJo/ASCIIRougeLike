#pragma once
class Monster
{
public:
	Monster();

	void init(int health, int attack, int defence);

	//setters
	void setPosition(int x, int y);
	void setHealth(int healthMod);

	//getters
	void getPosition(int& x, int& y);
	int getAttack();
	int getDefence();
	int getHealth();

private:
	//properties
	int _health;
	int _attack;
	int _defence;

	//position
	int _x;
	int _y;
};

