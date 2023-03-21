#include "StringifierClass.h"
using std::to_string;

string StringifierClass::HealthString(int _health, int _currentHealth)
{
	string _maxHealth = to_string(_health);
	string _current = to_string(_currentHealth);
	string _output = " {" + _current + "/" + _maxHealth + "} ";
	return _output;
}
