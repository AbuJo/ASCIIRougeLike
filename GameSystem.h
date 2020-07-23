#pragma once
#include "Player.h"
#include "Level.h"
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
	void endingScreen();
	void drawCombat(char monster);
	void combine2dGraphics(vector <string> _instertGraphic, vector <string> _main, int start_x, int start_y);

private:
	Player _player;
	Level _level;
	vector <string> _monsterGraphic;
	vector <string> _playerGraphic;
	vector <string> _frameGraphic;
};


