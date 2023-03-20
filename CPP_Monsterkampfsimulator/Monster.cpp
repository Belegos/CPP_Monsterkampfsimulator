#include "Monster.h"
#include <iostream>

void Monster::CreateMonster()
{
	monsterHealth = 100;
};

void Monster::PrintMonster()
{
	std::cout << "Monster Health: " << monsterHealth << std::endl;
};