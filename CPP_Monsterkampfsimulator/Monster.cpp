#include "Monster.h"
#include <iostream>
Monster::Monster() //constructor (no return type, same name as class
{
	//constructor code
}
Monster::~Monster() //destructor (no return type, same name as class, prefixed with ~)
{
	//destructor code

}
void Monster::CreateMonster()
{
	monsterHealth = 100;
};

void Monster::PrintMonster()
{
	std::cout << "Monster Health: " << monsterHealth << std::endl;
};