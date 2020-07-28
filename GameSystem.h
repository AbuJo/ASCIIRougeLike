#pragma once
#include "Player.h"
#include "Level.h"
#include "VectorHelper.h"
#include "CombatManager.h"
#include "GameDisplay.h"
#include <string>

using namespace std;

class GameSystem
{
public:
	GameSystem(string levelFile);
	void playGame();
	void processMove(int x, int y);
	void combatBegins(char monster);
	void loadingScreen();
	void endingScreen(bool victory);
	bool combat(char monster);

private:
	Player _player;
	Level _level;
	vector <string> _monsterGraphic;
	vector <string> _playerGraphic;
	vector <string> _frameGraphic;
	vector <string> _textGraphic;
};


