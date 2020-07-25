#pragma once
#include "Monster.h"
#include <random>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <ctime>

using namespace std;

class CombatManager
{
public:
	void buildMonster(char monster);
	int attack(int attack, int defence);

	CombatManager();
	~CombatManager();

private:
	Monster _monster;
	vector <string> _monsterStats;
};

