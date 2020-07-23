#pragma once
class Player
{

public:
	Player();

	void init(int level, int health, int attack, int defence, int experience);

	//setters
	void setPosition(int x, int y);

	//getters
	void getPosition(int& x, int& y);

private:
	//properties
	int _level;
	int _health;
	int _attack;
	int _defence;
	int _experience;

	//position
	int _x;
	int _y;

};

