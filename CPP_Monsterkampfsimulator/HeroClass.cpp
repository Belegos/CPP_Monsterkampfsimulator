#include "HeroClass.h"
#include <iostream>

int HeroClass::ModifyHealth()
{
	return _heroHealth;
}

void HeroClass::ModifyHealth(const int& _newHealth)
{
	_heroHealth = _newHealth;
}

int HeroClass::GetAttack()
{
	return _heroAttack;
}

void HeroClass::SetAttack(const int& _newAttack)
{
	_heroAttack = _newAttack;
}

int HeroClass::GetDefense()
{
	return _heroDefense;
}

void HeroClass::SetDefense(const int& _newDefense)
{
	_heroDefense = _newDefense;
}

int HeroClass::GetSpeed()
{
	return _heroSpeed;
}

void HeroClass::SetSpeed(const int& _newSpeed)
{
	_heroSpeed = _newSpeed;
}

