#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <thread>
#include "Commands.h"
#include "MainMenu.h"

//put these using to other classes where used
#include "StringifierClass.h"
#include "Monster.h"
#include "MonsterFactory.h"
//#include <SFML/Audio.hpp>

#pragma comment(lib, "winmm.lib")

using namespace std;
#pragma region NullPtrCheck and Obj delete
template<typename T>
void checkNullPtr(T*& pPointer)
{
	if (pPointer != nullptr) { pPointer = nullptr; }
	else {}
}
template<typename T>
void setPointerNullDeleteObject(T*& pPointer)
{
	if (pPointer != nullptr) { delete pPointer; };
	pPointer = nullptr;
}
#pragma endregion

#pragma region MusicThreaded
void playBackgroundMusic()
{
	wchar_t wstr[] = L"music.wav";
	PlaySound(wstr, NULL, SND_ASYNC | SND_LOOP);
}
void StartThreadedBackgroundMusic()
{
	//threaded backgroundmusic with SFML library
	std::thread musicThread(playBackgroundMusic);
	musicThread.detach();
}
#pragma endregion

int main()
{
	MainMenu* pMainMenu = nullptr;
	StringifierClass* pStringifierClass = nullptr;
	Commands* pCommands = nullptr;

	checkNullPtr(pMainMenu);
	checkNullPtr(pStringifierClass);
	checkNullPtr(pCommands);

	StartThreadedBackgroundMusic();

	pMainMenu = new MainMenu();
	pStringifierClass = new StringifierClass();
	pCommands = new Commands();

	// initilatation of objects for the game
	pMainMenu->StartMenu(pCommands);

	{ //Testing-Area
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
		setPointerNullDeleteObject(pMonster1);
		setPointerNullDeleteObject(pMonster2);
	}


	setPointerNullDeleteObject(pCommands);
	setPointerNullDeleteObject(pStringifierClass);
	setPointerNullDeleteObject(pMainMenu);
	return 0;
}
/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="pPointer"></param>

/*
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
*/

// int* pNumber -> Pointer to an integeradress
// &iNumber -> Adress of iNumber
// *pNumber -> Value of the adress of pNumber
// int* pNumber = &iNumber -> Pointer to the adress of iNumber
// int* pNumber = new int; -> Pointer to a new integeradress
// delete pNumber; -> free the adress of pNumber
// pNumber = nullptr; -> free the adress of pNumber

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