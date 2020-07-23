#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Player.h"

using namespace std;

class Level
{
public:
	Level();
	void loadLevel(string fileName, Player& player);
	void printLevel();
	char getTile(int x, int y);
	void setTile(int x, int y, char tile);

private:
	vector <string> _levelData;
};



