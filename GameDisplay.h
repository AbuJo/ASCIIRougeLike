#pragma once
#include "Player.h"
#include "Monster.h"
#include "Level.h"
#include "VectorHelper.h"
#include "CombatManager.h"
#include <string>


class GameDisplay
{
	//Overall class for drawing the onscreen combat, levels and what have you.
	//Theres alot of different things to draw at once, this acts as a manager to draw them correctly.
public:

	void drawScreen(int monsterHealth, char monsterChar, Player _player, int monOffset, int playerOffset, string message);
	void drawCombatScreen( char monsterChar, int monOffset, int playerOffset);
	void drawStatus(int playerHealth, int playerPotions, int monsterHealth);
	void drawCombatOptions();

private:
	vector <string> _monsterGraphic;
	vector <string> _playerGraphic;
	vector <string> _frameGraphic;
	vector <string> _textGraphic;
};

