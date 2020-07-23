#include <iostream>
#include <cstdlib>
#include <string>

#include "GameSystem.h"

using namespace std;

void  menu(GameSystem gameSystem)
{
	system("CLS");
	char choice;
	cout
		<< "						                       \\,/   								\n"
		<< "    The Tower of DOOM                        /`\\ 									\n"
		<< "    Jonathans Small Rougelike														\n"
		<< "                                     												\n"
		<< "    1--> Play Game                   [][][][]										\n"
		<< "    2--> Create A Level              ||:    |										\n"
		<< "    3--> Options                     ||:DOOM|										\n"
		<< "    4--> Quit                        ||:    |										\n"
		<< "    Enter Selection ==>              ||:.   |										\n"
		<< "                                     ||:  . |										\n"
		<< "                                     ||:    |	/'\\								\n"
		<< "                                     ||: ,  |            /`\\						\n"
		<< "                                     ||:    |										\n"
		<< "                                     ||: .  |										\n"
		<< "             __                      ||     |										\n"
		<< "    ____--`~    '--~~__             ~~--~----~`--               ___'			    \n"
		<< "-~--~                   ~---__ ,--~'             '~~----_____-~'   `~----~~		    \n";

	cin >> choice;


	switch (choice) {
		case '1':
			gameSystem.playGame();
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			exit(0);
		default:
			system("CLS");
			cout << "\t\t\t Invalid Option Try Again...";
			cout << "\n\n";
	}

	menu(gameSystem);
}

int main() {
	GameSystem gameSystem("Level.txt");
	menu(gameSystem);
	return 0;
}


// The game should have 10 levels, and each floor should be clearable.
// once the player has killed all the goblins in a given floor the stairs will work
// the combat should seem siliar to fire emblem or pokemon, where a player can transition ionto a combat screen