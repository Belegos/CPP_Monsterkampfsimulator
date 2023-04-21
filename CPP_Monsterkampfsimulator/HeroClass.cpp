#include "HeroClass.h"
#include <iostream>
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_newHealth"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifyHealth()
{
	return _heroHealth;
}
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_newHealth"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifyHealth(const int& _newHealth)
{
	_heroHealth = _newHealth;
	return _heroHealth;
}
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_heroAttack"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifyAttack()
{
	return _heroAttack;
}
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_heroAttack"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifyAttack(const int& _newAttack)
{
	_heroAttack = _newAttack;
	return _heroAttack;
}
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_heroDefense"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifyDefense()
{
	return _heroDefense;
}
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_heroDefense"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifyDefense(const int& _newDefense)
{
	_heroDefense = _newDefense;
	return _heroDefense;
}
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_heroSpeed"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifySpeed()
{
	return _heroSpeed;
}
/// <summary>
/// This method can be used without any attribute to return the value.
/// Used with an integer as an attribute it sets the new value.
/// </summary>
/// <param name="_heroSpeed"></param>
/// <returns>Returns modifyed value</returns>
int HeroClass::ModifySpeed(const int& _newSpeed)
{
	_heroSpeed = _newSpeed;
	return _heroSpeed;
}

