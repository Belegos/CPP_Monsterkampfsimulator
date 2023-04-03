#include "HeroClass.h"
#include <iostream>

int HeroClass::ModifyHealth()
{
	return _heroHealth;
}

int HeroClass::ModifyHealth(const int& _newHealth)
{
	_heroHealth = _newHealth;
	return _heroHealth;
}

int HeroClass::ModifyAttack()
{
	return _heroAttack;
}

int HeroClass::ModifyAttack(const int& _newAttack)
{
	_heroAttack = _newAttack;
	return _heroAttack;
}

int HeroClass::ModifyDefense()
{
	return _heroDefense;
}

int HeroClass::ModifyDefense(const int& _newDefense)
{
	_heroDefense = _newDefense;
	return _heroDefense;
}

int HeroClass::ModifySpeed()
{
	return _heroSpeed;
}

int HeroClass::ModifySpeed(const int& _newSpeed)
{
	_heroSpeed = _newSpeed;
	return _heroSpeed;
}

