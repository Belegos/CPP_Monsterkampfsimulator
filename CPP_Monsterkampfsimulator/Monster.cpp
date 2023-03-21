#include "Monster.h"
#include <iostream>
using std::cout;
using std::to_string;
Monster::Monster(int _raceChoice) //constructor (no return type, same name as class
{
	//constructor code
	switch (_raceChoice)
	{
	case 1:
		_monsterAttack = 20;
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterHealth = 80;
		_monsterRace = "DRAGON";
		break;
	case 2:
		_monsterAttack = 10;
		_monsterDefense = 10;
		_monsterSpeed = 10;
		_monsterHealth = 7;
		_monsterRace = "GOBLIN";
		break;
	case 3:
		_monsterAttack = 20;
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterHealth = 80;
		_monsterRace = "OGRE";
		break;
	case 4:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "ORC";
		break;
	case 5:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "SKELETON";
		break;
	case 6:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "TROLL";
		break;
	case 7:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "VAMPIRE";
		break;
	case 8:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "ZOMBIE";
		break;
	}
	_currentHealth = _monsterHealth;
};
const enum MonsterType 
{
	DRAGON,
	GOBLIN,
	OGRE,
	ORC,
	SKELETON,
	TROLL,
	VAMPIRE,
	ZOMBIE,
	MAX_MONSTER_TYPES
};

// Property Getters and Setters
int Monster::GetHealth()
{
	return _currentHealth;
};
void Monster::SetHealth(int _newHealth)
{
	_currentHealth = _newHealth;
};
int Monster::GetMaxHealth() 
{
	return _monsterHealth;
};
void Monster::SetMaxHealth(int _newHealth)
{
	_monsterHealth = _newHealth;
};
// end of Property Getters and Setters