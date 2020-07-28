#include "GameSystem.h"
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
		//Combat with ghost
		combatBegins('G');
		break;

	case 'H':
		//Combat with ghost
		combatBegins('H');
		break;

	case 'h':
		//Combat with ghost
		_player.addHealthPot(1);
		_player.setPosition(x, y);
		_level.setTile(x, y, '@');
		_level.setTile(prevX, prevY, '.');

	case 'S':
		// Set next level. save this level.

		break;

	}
}

void GameSystem::combatBegins(char monster) {
	//Transition
	loadingScreen();
	bool victory = combat(monster);
	endingScreen(victory);
}

void GameSystem::loadingScreen() {
	system("cls");
	_frameGraphic.clear();

	VectorHelper v1;
	v1.loadVector(_frameGraphic, "transitionbackground.txt");
	v1.loadVector(_textGraphic, "introtext.txt");
	v1.overlayVector(_textGraphic, _frameGraphic, 10, 5);
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

	if (victory == false) {
		Sleep(2000);
		exit(0);
	}


}

bool GameSystem::combat(char monster) {
	GameDisplay gameDisplay;

	CombatManager combatManager;
	combatManager.buildMonster(monster);

	gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, 0, 0, "");


	bool victory = false;
	bool combatDone = false;
	char turn = 'P';

	while (combatDone != true) {
		char choice;
		cin >> choice;
		string message = "";
		int playerAttack = 0;
		int monsterAttack = 0;

		switch (choice) {
		case '1':
			//Attack the Monster
			playerAttack = combatManager.attack(_player.getAttack(), combatManager.getMonsterDefence());
			combatManager.damageMonster(playerAttack);

			//Animate Monster Damaged
			gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, 1, 0, ""); Sleep(100);
			gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, -1, 0, ""); Sleep(100);
			gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, 0, 0, ""); Sleep(100);

			Sleep(800);

			//Monster Attacks the Player
			monsterAttack = combatManager.attack(combatManager.getMonsterAttack(), _player.getDefence());
			_player.setHealth(monsterAttack);

			//Animate Player Damaged
			gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, 0, 1, ""); Sleep(100);
			gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, 0, -1, ""); Sleep(100);
			gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, 0, 0, ""); Sleep(100);

			break;
		case '2':
			//Health Potion Used.
			if (_player.getHealthPots() == 0) {
				message = "No more health potions to use";
			}
			else {
				_player.addHealthPot(-1);
				_player.setHealth(20);
			}
			gameDisplay.drawScreen(combatManager.getMonsterHealth(), monster, _player, 0, 0, message);
			break;
		case '3':
			//Run away
			combatDone = true;
			victory = false;
			break;
		default:
			//Bad Input
			break;
		}

		if (_player.getHealth() <= 0) {
			combatDone = true;
			victory = false;
		} else if (combatManager.getMonsterHealth() <= 0) {
			combatDone = true;
			victory = true;
			int experience = 0;
			switch (monster) {
				case 'G':
					experience = 50;
					break;
				case 'H':
					experience = 70;
					break;
			}
			_player.setExperience(experience);

		}
		else {
			turn = 'M';
		}
	}
	return victory;
}
