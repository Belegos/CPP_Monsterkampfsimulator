#include "MainMenu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

/// <summary>
/// The "StartMenu" function displays a menu with three options and
/// allows the user to navigate and select an option using arrow keys and the enter key. 
/// </summary>
void MainMenu::StartMenu(
	Commands* const pCommands, 
	Artwork* const pArtwork, 
	std::thread* const pMusicThread,
	MainMenu* const pMainMenu, 
	bool* pMusicIsPlaying, 
	HeroClass* pHeroClass,
	HeroCreationMenu* pHeroCreationMenu)// const = read only Pointer, to prevent creating a new obj on the pointer while using 
{
	int Set[] = { 12,7,7,7 };	// 7 = white , 12 = red
	int _menuPoint = 1;

	pArtwork->Title();
	while (true)
	{
		pCommands->GoToXY(0, 0);
		pCommands->GoToXY(10, 18);//set cursor position
		pCommands->Color(Set[0]);
		cout << "1. Start Game";

		pCommands->GoToXY(10, 19);
		pCommands->Color(Set[1]);
		cout << "2. Options";

		pCommands->GoToXY(10, 20);
		pCommands->Color(Set[2]);
		cout << "3. Help";

		pCommands->GoToXY(10, 21);
		pCommands->Color(Set[3]);
		cout << "4. Exit";
		pCommands->Color(7);

		pCommands->GoToXY(10, 23);
		pCommands->Color(7);
		cout << "Use the arrow keys to navigate and";

		pCommands->GoToXY(10, 24);
		cout << "the enter key to select an option." << endl;


		char key = _getch();		// reads a single character from the keyboard without echoing it to the console.

		if (key == 80 && (_menuPoint >= 1 && _menuPoint <= 3))		//if key pressed is down arrow
		{
			_menuPoint++;
		}
		else if (key == 72 && (_menuPoint >= 2 && _menuPoint <= 4))	//if key pressed is up arrow
		{
			_menuPoint--;
		}
		else if (key == 13)	//if key pressed is enter
		{
			if (_menuPoint == 1)
			{
				//start game
				pCommands->GoToXY(10, 22);
				pCommands->ClearCurrentLine();
				cout << "START GAME" << "\r" << endl;
				pHeroCreationMenu->StartHeroCreation(pHeroClass, pCommands);
				break;
			}
			else if (_menuPoint == 2)
			{
				//help
				pCommands->GoToXY(10, 22);
				pCommands->ClearCurrentLine();
				cout << "OPTIONS" << "\r" << endl;
				DisplayOptions(pCommands, pArtwork, pMusicThread, this, pMusicIsPlaying, pHeroClass, pHeroCreationMenu);
				break;
			}
			else if (_menuPoint == 3)
			{
				//help
				pCommands->ClearLine(22);
				pCommands->GoToXY(10, 22);
				cout << "USE ARROW KEYS AND ENTER TO SELECT" << "\r" << endl;
				continue;
			}
			else if (_menuPoint == 4)
			{
				pCommands->ClearLine(22);
				pCommands->GoToXY(10, 22);
				cout << "EXIT" << "\r" << endl;
				exit(0);
			}
			break;
		}

		Set[0] = 7; //color.white (default)
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;

		switch (_menuPoint)
		{
		case 1:
			Set[0] = 12; //color.red
			break;
		case 2:
			Set[1] = 12;
			break;
		case 3:
			Set[2] = 12;
			break;
		case 4:
			Set[3] = 12;
			break;
		}
	}
}

void MainMenu::DisplayOptions
(
	Commands* const pCommands, 
	Artwork* const pArtwork, 
	std::thread* pMusicThread, 
	MainMenu* const pMainMenu, 
	bool* pMusicIsPlaying, 
	HeroClass* pHeroClass, 
	HeroCreationMenu* pHeroCreationMenu
)
{
	int counter = 1;
	int Set[] = { 12,7 };	// 7 = white , 12 = red

	system("cls");
	pCommands->GoToXY(0, 0);
	pArtwork->Options();
	pCommands->GoToXY(10, 7);//set cursor position
	pCommands->Color(Set[1]);
	cout << "Options";

	while (true)
	{

		pCommands->GoToXY(10, 9);
		pCommands->Color(Set[0]);
		cout << "1. Sound";

		pCommands->GoToXY(10, 10);
		pCommands->Color(Set[1]);
		cout << "2. Back";



		const char key = _getch();		// reads a single character from the keyboard without echoing it to the console.

		if (key == 80 && (counter >= 1 && counter <= 1))		//if key pressed is down arrow
		{
			counter++;
		}
		else if (key == 72 && (counter >= 2 && counter <= 2))	//if key pressed is up arrow
		{
			counter--;
		}
		else if (key == 13)	//if key pressed is enter
		{
			if (counter == 1 && key == 13)
			{
				if (pMusicThread != nullptr)
				{
					if (*pMusicIsPlaying)
					{
						//pMusicThread->join();
						PlaySound(NULL, NULL, 0);
						delete pMusicThread;
						pMusicThread = nullptr;
						*pMusicIsPlaying = false;
						pCommands->GoToXY(20, 9);
						cout << " Off " << endl;
						break;
					}
					else
					{
						wchar_t wstr[] = L"music.wav";
						delete pMusicThread;
						pMusicThread = nullptr;
						pCommands->StartThreadedBackgroundMusic(pMusicIsPlaying, pMusicThread);
						//creating new thread and detach(called in method) it!
						*pMusicIsPlaying = true;
						pCommands->GoToXY(20, 9);
						cout << "  ON" << endl;
						break;
					}
				}
				continue;
			}
			else if (counter == 2)
			{
				pCommands->Color(7);
				system("cls");
				pMainMenu->StartMenu(pCommands, pArtwork, pMusicThread, pMainMenu, pMusicIsPlaying, pHeroClass, pHeroCreationMenu);
			}
			break;
		}
		Set[0] = 7; //color.white (default)
		Set[1] = 7;

		switch (counter)
		{
		case 1:
			Set[0] = 12; //color.red
			break;
		case 2:
			Set[1] = 12;
			break;
		}
	}
}