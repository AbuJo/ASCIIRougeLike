#include "GameSystem.h"
#include <conio.h>
#include <windows.h>

//Contstructor
GameSystem::GameSystem(string levelFile) {
	_player.init(1, 100, 10, 10, 0);
	_level.loadLevel(levelFile, _player);
}

void GameSystem::playGame() {
	bool isDone = false;
	bool badInput = false;
	while (isDone != true) {
		system("CLS");


		_level.printLevel();
		if(badInput == true){
			printf("Invalid Input\n");
			badInput = false;
		}
		printf("Movement Commands w a s d\n");
		printf("To Exit, type q\n");

		int x;
		int y;
		_player.getPosition(x, y);
		printf("Player Position: X: %d Y: %d", x, y);

		char input;
		input = _getch();
		switch (input) {
		case 'w':
		case 'W':
			processMove(x, y - 1);
			break;
		case 's':
		case 'S':
			processMove(x, y + 1);
			break;
		case 'a':
		case 'A':
			processMove(x - 1, y);
			break;
		case 'd':
		case 'D':
			processMove(x + 1, y);
			break;
		case 'q':
		case 'Q':
			isDone = true;
			break;
		default:
			badInput = true;
			break;
		}
	}
}

void GameSystem::processMove(int x, int y) {
	int prevX;
	int prevY;

	_player.getPosition(prevX, prevY);
	char tile = _level.getTile(x, y);

	switch (tile) {
	case '#':
		break;
	case '.':
		//Update player position
		_player.setPosition(x, y);
		_level.setTile(x, y, '@');
		_level.setTile(prevX, prevY, '.');
		break;

	case 'G':
		//Combat Begins
		combatBegins('G');
		break;
	}

}

void GameSystem::combatBegins(char monster) {
	//Transition
	loadingScreen();
	drawCombat(monster);
	endingScreen();
}

void GameSystem::loadingScreen() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 55; j++) {
			printf("X");
			Sleep(1);
		}
		printf("\n");
	}
	Sleep(2000);
}

void GameSystem::endingScreen() {
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 55; j++) {
			printf("X");
		}
		printf("\n");
	}
	Sleep(2000);

}

void GameSystem::drawCombat(char monster) {
	// Establish a pokemon esk combat screen
	// laod the specific monster into the file
	string first(1, monster);
	string monsterFile = first + ".txt";

	ifstream file;
	file.open(monsterFile);
	if (file.fail()) {
		perror(monsterFile.c_str());
		system("PAUSE");
		exit(1);
	}
	string line;
	while (getline(file, line)) {
		_monsterGraphic.push_back(line);
	}
	file.close();

	string framefile = "frame.txt";
	file.open(framefile);
	if (file.fail()) {
		perror(framefile.c_str());
		system("PAUSE");
		exit(1);
	}
	while (getline(file, line)) {
		_frameGraphic.push_back(line);
	}
	file.close();
	system("cls");
	//Overlay the monster grapghic to the frame graphic starting at x = 5 and y = 2 
	combine2dGraphics(_monsterGraphic, _frameGraphic, 5, 2);
	for (int y = 0; y < _frameGraphic.size() ; y++) {
		for (int x = 0; x < _frameGraphic[y].length(); x++) {
			printf("%c", _frameGraphic[y][x]);
		}
		printf("\n");
	}
	system("PAUSE");
}
	//Now monster file will contain the data
void GameSystem::combine2dGraphics(vector <string> _instertGraphic, vector <string> _main, int start_x, int start_y) {
	// Loop through and overlay
	for (int y = 0; y < _instertGraphic.size(); y++) {
		for (int x = 0; x < _instertGraphic[y].length(); x++) {
			//For every element in insert_graphic
			_main[y + start_y][x + start_x] = _instertGraphic[y][x];
		}
	}

	_frameGraphic = _main;
}