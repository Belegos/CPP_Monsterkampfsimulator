﻿#include "Monster.h"
#include <iostream>
using std::cout;
using std::to_string;
Monster::Monster(const int& _raceChoice) //constructor (no return type, same name as class
{
	//constructor code
	switch (_raceChoice)
	{
	case 1:
		_monsterAttack = 20;
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterHealth = 80;
		_monsterRace = "Dragon";
		break;
	case 2:
		_monsterAttack = 10;
		_monsterDefense = 10;
		_monsterSpeed = 10;
		_monsterHealth = 7;
		_monsterRace = "Goblin";
		break;
	case 3:
		_monsterAttack = 20;
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterHealth = 80;
		_monsterRace = "Ogre";
		break;
	case 4:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "Orc";
		break;
	case 5:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "Skeleton";
		break;
	case 6:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "Troll";
		break;
	case 7:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "Vampire";
		break;
	case 8:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "Zombie";
		break;
	}
	_currentHealth = _monsterHealth;
};

//TODO: Use enum to define _monsterRace
const enum class MonsterType 
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
int Monster::ModifyHealth()
{
	return _monsterHealth;
}

int Monster::ModifyHealth(const int& _newHealth)
{
	_monsterHealth = _newHealth;
	return _monsterHealth;
}

int Monster::ModifyAttack()
{
	return _monsterAttack;
}

int Monster::ModifyAttack(const int& _newAttack)
{
	_monsterAttack = _newAttack;
	return _monsterAttack;
}

int Monster::ModifyDefense()
{
	return _monsterDefense;
}

int Monster::ModifyDefense(const int& _newDefense)
{
	_monsterDefense = _newDefense;
	return _monsterDefense;
}

int Monster::ModifySpeed()
{
	return _monsterSpeed;
}

int Monster::ModifySpeed(const int& _newSpeed)
{
	_monsterSpeed = _newSpeed;
	return _monsterSpeed;
}


int Monster::GetHealth()
{
	return _currentHealth;
};
void Monster::SetHealth(const int& _newHealth)
{
	_currentHealth = _newHealth;
};
int Monster::GetMaxHealth() 
{
	return _monsterHealth;
};
void Monster::SetMaxHealth(const int& _newHealth)
{
	_monsterHealth = _newHealth;
};
// end of Property Getters and Setters