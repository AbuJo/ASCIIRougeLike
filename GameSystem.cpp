#include "GameSystem.h"
#include "VectorHelper.h"
#include "CombatManager.h"
#include <conio.h>


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
	bool victory = conductCombat(monster);
	endingScreen(victory);
}

void GameSystem::loadingScreen() {
	system("cls");
	_frameGraphic.clear();

	VectorHelper v1;
	v1.loadVector(_frameGraphic, "transitionbackground.txt");
	v1.loadVector(_textGraphic, "introtext.txt");
	v1.overlayVector(_textGraphic, _frameGraphic, 8, 5);
	v1.printfVector(_frameGraphic, true);

	_frameGraphic.clear();
	_textGraphic.clear();
}

void GameSystem::endingScreen(bool victory) {
	system("cls");

	string framefile;
	if (victory == true) {
		framefile = "wintext.txt";
	}
	else {
		framefile = "losetext.txt";
	}

	VectorHelper v1;
	v1.loadVector(_frameGraphic, "transitionbackground.txt");
	v1.loadVector(_textGraphic, framefile);
	v1.overlayVector(_textGraphic, _frameGraphic, 8, 5);
	v1.printfVector(_frameGraphic, true);

	_frameGraphic.clear();
	_textGraphic.clear();
}

void GameSystem::drawCombat(char monster) {
	system("cls");
	// Establish a pokemon esk combat screen
	// laod the specific monster into the file
	string first(1, monster);
	string monsterFile = first + ".txt";

	_frameGraphic.clear();
	_monsterGraphic.clear();
	_playerGraphic.clear();
	_textGraphic.clear();

	VectorHelper v1;

	v1.loadVector(_frameGraphic, "frame.txt");
	v1.loadVector(_monsterGraphic, monsterFile);
	v1.loadVector(_playerGraphic, "playergraphic.txt");
	v1.loadVector(_textGraphic, "combatoptions.txt");

	v1.overlayVector(_monsterGraphic, _frameGraphic, 36, 1);
	v1.overlayVector(_playerGraphic, _frameGraphic, 1, 1);

	v1.printfVector(_frameGraphic, false);
	v1.printfVector(_textGraphic, false);

	system("Pause");

	_textGraphic.clear();
	_frameGraphic.clear();
	_monsterGraphic.clear();
	_playerGraphic.clear();
}

//Player engages in combat with a monster
bool GameSystem::conductCombat(char monster) {
	CombatManager combatManager;
	combatManager.buildMonster(monster);

	bool victory = false;
	bool combatDone = false;

	while (combatDone != true) {
		char choice;

		cin >> choice;

		switch (choice) {
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
		default:

		}
	}
	return true;
}