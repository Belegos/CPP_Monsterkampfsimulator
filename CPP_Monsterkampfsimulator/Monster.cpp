#include "Monster.h"
#include <iostream>
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
	case 2:
		_monsterAttack = 10;
		_monsterDefense = 10;
		_monsterSpeed = 10;
		_monsterHealth = 7;
		_monsterRace = "GOBLIN";
	case 3:
		_monsterAttack = 20;
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterHealth = 80;
		_monsterRace = "OGRE";
	case 4:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "ORC";
	case 5:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "SKELETON";
	case 6:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "TROLL";
	case 7:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "VAMPIRE";
	case 8:
		_monsterDefense = 20;
		_monsterSpeed = 10;
		_monsterAttack = 20;
		_monsterHealth = 10;
		_monsterRace = "ZOMBIE";
	}
}
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
//Monster::~Monster() //destructor (no return type, same name as class, prefixed with ~)
//{
//	//destructor code
//
//}
void Monster::CreateMonster()
{
	_monsterHealth = 100;
};

void Monster::PrintMonster()
{
	std::cout << "Monster Health: " << _monsterHealth << std::endl;
};