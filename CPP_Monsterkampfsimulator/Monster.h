#pragma once
#include <string> //also in .cpp?
using std::string; //also in .cpp?
class Monster {
public:
	void PrintMonster();
	void CreateMonster();
	const enum MonsterType;
	Monster(int _raceChoice);
private:
	int _monsterHealth{}; //braces initialize to zero
	int _monsterAttack{};
	int _monsterDefense{};
	int _monsterSpeed{};
	string _monsterRace{};
	int PlayerChoise{};
};;
