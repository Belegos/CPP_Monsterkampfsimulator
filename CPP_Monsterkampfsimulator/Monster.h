#pragma once
#include <string> 
using std::string; 
class Monster 
{
public:
	int ModifyHealth();
	int ModifyHealth(const int& _newHealth);
	int ModifyAttack();
	int ModifyAttack(const int& _newAttack);
	int ModifyDefense();
	int ModifyDefense(const int& _newDefense);
	int ModifySpeed();
	int ModifySpeed(const int& _newSpeed);
	int GetHealth();
	void SetHealth(const int& _newHealth);
	int GetMaxHealth();
	void SetMaxHealth(const int& _newHealth);
	const enum class MonsterType;
	Monster(const int& _raceChoice);
	string _monsterRace{};
	
private:
	int _monsterHealth{};
	int _currentHealth{_monsterHealth};
	int _monsterAttack{};
	int _monsterDefense{};
	int _monsterSpeed{};
	int PlayerChoise{};
};;
