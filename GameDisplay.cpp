#include "GameDisplay.h"

//Main fucntion for drawing the combat screen.
void GameDisplay::drawScreen(int monsterHealth, char monsterChar, Player _player, int monOffset, int playerOffset, string message) {
	
	//Need to find a better alternative to CLS (how does df do it)
	system("CLS");

	//Need to load all data, then print out the data in order each time this function is called.
	//We are going to be adding everything to the _frameGraphic and then printing that. 

	//Load combat screen
	drawCombatScreen(monsterChar, monOffset, playerOffset);

	//Load status Bar
	drawStatus(_player.getHealth(), _player.getHealthPots(), monsterHealth);

	//Load combat options
	drawCombatOptions();

	printf("\n %s", message);
	printf("Choose Option >>>");

}

void GameDisplay::drawCombatScreen(char monster, int monOffset, int playerOffset) {
	// Establish a pokemon esk combat screen
	// laod the specific monster into the file
	string first(1, monster);
	string monsterFile = first + ".txt";

	_frameGraphic.clear();
	_monsterGraphic.clear();
	_playerGraphic.clear();

	VectorHelper v1;

	v1.loadVector(_frameGraphic, "frame.txt");
	v1.loadVector(_monsterGraphic, monsterFile);
	v1.loadVector(_playerGraphic, "playergraphic.txt");

	v1.overlayVector(_monsterGraphic, _frameGraphic, 36 + monOffset, 10);
	v1.overlayVector(_playerGraphic, _frameGraphic, 1 + playerOffset, 1);

	v1.printfVector(_frameGraphic, false);

	_frameGraphic.clear();
	_monsterGraphic.clear();
	_playerGraphic.clear();

}

void GameDisplay::drawStatus(int playerHealth, int playerPotions, int monsterHealth) {
	printf("#######################################################\n");
	printf("# Player Health: ");

	int t = 0;
	for (int i = 0; i < playerHealth / 10; i++) {
		if (t == 0) {
			printf("<");
			t = 1;
		}
		else {
			t = 0;
			printf(">");
		}
	}

	printf("\n# Monster Health: ");

	t = 0;
	for (int i = 0; i < monsterHealth / 10; i++) {
		if (t == 0) {
			printf("<");
			t = 1;
		}
		else {
			t = 0;
			printf(">");
		}
	}

	if (playerPotions == 1) {
		printf("\n You have 1 Health Pot Remaining");
	}
	else {
		printf("\n You have %d Health Pots Remaining", playerPotions);
	}

	printf("\n#######################################################\n");
}

void GameDisplay::drawCombatOptions() {
	_textGraphic.clear();
	VectorHelper v1;
	v1.loadVector(_textGraphic, "combatoptions.txt");
	v1.printfVector(_textGraphic, false);
	_textGraphic.clear();
}