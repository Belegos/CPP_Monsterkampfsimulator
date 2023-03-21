#pragma once

class Monster {
public:
	void PrintMonster();
	void CreateMonster();
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
	Monster(int _raceChoice)
	{
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
private:
	int _monsterHealth{}; //braces initialize to zero
	int _monsterAttack{};
	int _monsterDefense{};
	int _monsterSpeed{};
	string _monsterRace{};
	int PlayerChoise{};
};;
