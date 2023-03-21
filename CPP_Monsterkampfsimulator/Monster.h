#pragma once
#include <string> //also in .cpp?
using std::string; //also in .cpp?
class Monster {
public:
	void PrintHealth();
	string HealthDisplay();
	enum MonsterType;
	Monster(int _raceChoice);
	
private:
	int _monsterHealth{}; //braces initialize to zero
	int _currentHealth{_monsterHealth};
	int _monsterAttack{};
	int _monsterDefense{};
	int _monsterSpeed{};
	string _monsterRace{};
	int PlayerChoise{};
};;
