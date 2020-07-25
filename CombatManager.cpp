#include "CombatManager.h"
CombatManager::CombatManager() {

}
CombatManager::~CombatManager() {

}

void CombatManager::buildMonster(char monster) {

	string first(1, monster);
	string monsterFile = first + "stat.txt";

	ifstream file;
	string inputFile = monsterFile;
	file.open(inputFile);
	if (file.fail()) {
		perror(inputFile.c_str());
		system("PAUSE");
		exit(1);
	}
	string line;
	while (getline(file, line)) {
		_monsterStats.push_back(line);
	}
	file.close();

	//Now need to convert each line of _monsterStats into ints to initialise the goblin

}

int CombatManager::attack(int attack, int defence) {
	// Judge an attack based on whether it outrolls a defence stat
	
	default_random_engine randomEngine(time(0));
	uniform_int_distribution<int> attackRoll(0, 10);

	float attackResult = attackRoll(randomEngine);
	int attackReturn = 0;

	if (attackResult > defence) {
		attackReturn = attack*-1;
	}
	return attackReturn;
}