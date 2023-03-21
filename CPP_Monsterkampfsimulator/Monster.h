#pragma once
#include <string> //also in .cpp?
using std::string; //also in .cpp?
class Monster {
public:
	int GetHealth();
	void SetHealth(int _newHealth);
	int GetMaxHealth();
	void SetMaxHealth(int _newHealth);
	enum MonsterType;
	Monster(int _raceChoice);
	string _monsterRace{};
	
private:
	int _monsterHealth{}; //braces initialize to zero
	int _currentHealth{_monsterHealth};
	int _monsterAttack{};
	int _monsterDefense{};
	int _monsterSpeed{};
	int PlayerChoise{};
};;
