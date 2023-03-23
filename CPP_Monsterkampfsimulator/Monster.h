#pragma once
//#include <string> //also in .cpp?
using std::string; //also in .cpp?
class Monster 
{
public:
	int GetHealth();
	void SetHealth(const int& _newHealth);
	int GetMaxHealth();
	void SetMaxHealth(const int& _newHealth);
	const enum class MonsterType;
	Monster(const int& _raceChoice);
	string _monsterRace{};
	
private:
	int _monsterHealth{}; //braces initialize to zero
	int _currentHealth{_monsterHealth};
	int _monsterAttack{};
	int _monsterDefense{};
	int _monsterSpeed{};
	int PlayerChoise{};
};;
