#include <iostream>
#include "CPP_Monsterkampfsimulator.h"
#include "MainMenu.h"
#include "StringifierClass.h"
#include "Monster.h"
#include "MonsterFactory.h"
using namespace std;
int main()
{
	/*
	
	// initilatation of objects for the game
	MainMenu menuObj;
	StringifierClass strings{};
	Monster obj1{ 1 };

	menuObj.StartMenu();
	//redundent because only on stack
	delete& obj1;
	delete& strings;
	delete& menuObj;
	*/

	//std::nullptr_t nullPtr = nullPtr; //leere Speicheradresse um Pointer vorzueinstellen
	Monster* pMonster = nullptr;

	MonsterFactory* factory = new FactoryDragon();
	Monster* dragon = factory->createMonster();
	if (pMonster != nullptr)pMonster = nullptr;
	else
	{
		pMonster = dragon;
	}
	cout << "Monster: "<< pMonster << endl;

	/********************************/
	/*
	//TODO: add nullptr check
	//create NullPointer
	MainMenu* pMainMenu = nullptr;
	//Ctor -> Constructor -> give Pointer Heap-Adress
	pMainMenu = new MainMenu();
	pMainMenu->StartMenu();
	//Dtor -> Destructor
	delete pMainMenu;
	//free Heap-Adress
	pMonster = nullptr;
	*/
	/********************************/


	return 0;
}


//cout << obj1._monsterRace<< "\n"<< "Life:" << strings.HealthString(obj1.GetMaxHealth(), obj1.GetHealth()) << endl;






//printf("Monster Health: %s", obj1.HealthDisplay());
//std::cout << "Hallo Andre" << std::endl;
//cout << "so geht's auch!"<< endl;

//cout << "type something and I will repeat: ";
//char sz[256];
//cin >> sz; //>> is the extraction operator, << is the insertion operator
//cout << "You typed: " << sz << endl; //repeats only the first word

//cout << "type something and I will repeat: ";
//cin.getline(sz, 256); //cin.getline() reads a whole line
//cout << "You typed: " << sz << endl; //repeats the whole line