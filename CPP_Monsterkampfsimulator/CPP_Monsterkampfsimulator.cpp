#include <iostream>
#include <thread>
#include <SFML/Audio.hpp>
#include "CPP_Monsterkampfsimulator.h"
#include "MainMenu.h"
#include "StringifierClass.h"
#include "Monster.h"
#include "MonsterFactory.h"
using namespace std;

void playBackgroundMusic() 
{
	sf::Music music;
	if (!music.openFromFile("music.mp3")) 
	{
		return;
	}
	music.setLoop(true);
	music.play();
}

int main()
{
	std::thread musicThread(playBackgroundMusic);
	musicThread.detach();
	// initilatation of objects for the game
	MainMenu menuObj;
	StringifierClass strings{};

	menuObj.StartMenu();
	
	Monster* pMonster1 = nullptr;
	Monster* pMonster2 = nullptr;

	MonsterFactory* factory = new FactoryDragon();
	if (pMonster1 != nullptr) { pMonster1 = nullptr; }
	pMonster1 = factory->createMonster();

	factory = new FactoryGoblin();
	if (pMonster2 != nullptr) { pMonster2 = nullptr; }
	pMonster2 = factory->createMonster();

	cout << "Monster1: " << pMonster1->_monsterRace << endl;
	cout << "Monster2: " << pMonster2->_monsterRace << endl;

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
	
	if (pMonster1 != nullptr)
	{
		delete pMonster1;
		pMonster1 = nullptr;
	}
	if (pMonster2 != nullptr)
	{
		delete pMonster2;
		pMonster2 = nullptr;
	}

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