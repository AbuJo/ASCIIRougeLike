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
	int health = stoi(_monsterStats[0]);
	int attack = stoi(_monsterStats[1]);
	int defence = stoi(_monsterStats[2]);

	_monster.init(health, attack, defence);


}

// Attackers attack damage and degenders defence stat.
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

// Get a monsters attack damage
int CombatManager::getMonsterAttack() {
	return _monster.getAttack();
}

// Get a monsters Defence
int CombatManager::getMonsterDefence() {
	return _monster.getDefence();
}

int CombatManager::getMonsterHealth() {
	return _monster.getHealth();
}

//reduce health of the monster
void CombatManager::damageMonster(int attack) {
	_monster.setHealth(attack);
	if (_monster.getHealth() < 0) {
		//set health to 0
		_monster.setHealth(_monster.getHealth()*-1);
	}
}