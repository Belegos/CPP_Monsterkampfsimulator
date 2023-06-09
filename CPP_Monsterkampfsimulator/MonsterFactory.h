#pragma once
#include "Monster.h"
class MonsterFactory
{
public:
	virtual Monster* createMonster() = 0;
};

class FactoryDragon : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(1);
	}
};

class FactoryGoblin : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(2);
	}
};

class FactoryOgre : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(3);
	}
};

class FactoryOrc : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(4);
	}
};

class FactorySkeleton : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(5);
	}
};

class FactoryTroll : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(6);
	}
};

class FactoryVampire : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(7);
	}
};

class FactoryZombie : public MonsterFactory {
public:
	virtual Monster* createMonster()
	{
		return new Monster(8);
	}
};