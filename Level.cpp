#include "Level.h"

Level::Level() {

}

void Level::loadLevel(string levelData, Player& player) {
	// Load level from data
	ifstream file;
	file.open(levelData);
	if (file.fail()) {
		perror(levelData.c_str());
		system("PAUSE");
		exit(1);
	}
	string line;
	while (getline(file, line)) {
		_levelData.push_back(line);
	}
	file.close();

	// Process the level
	char tile;
	for (int i = 0; i < _levelData.size(); i++) {
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];
			switch (tile)
			{
			case '@':
				player.setPosition(j, i);
				break;
			default:
				break;
			}

		}
	}

}

void Level::printLevel() {
	system("CLS");
	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

char Level::getTile(int x, int y) {
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile) {
	_levelData[y][x] = tile;
}