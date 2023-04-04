#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
//#include <thread>
#include <Windows.h>
//#include <mmsystem.h>
#include "MainMenu.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

//#define pCommands pGlobalParameters->pCommands
//#define pArtwork pGlobalParameters->pArtwork
//#define pMusicThread pGlobalParameters->pMusicThread
//#define pMainMenu pGlobalParameters->pMainMenu
//#define pMusicIsPlaying pGlobalParameters->pMusicIsPlaying
//#define pHeroClass pGlobalParameters->pHeroClass
//#define pHeroCreationMenu pGlobalParameters->pHeroCreationMenu

void MainMenu::StartMenu(GlobalParameters* pGlobalParameters)
{
	int Set[] = { 12,7,7,7 };	// 7 = white , 12 = red
	int _menuPoint = 1;
	
	pGlobalParameters->pArtwork->Title();
	for (int i = 1;;)
	{
		
		pGlobalParameters->pCommands->GoToXY(0, 0);
		pGlobalParameters->pCommands->GoToXY(10, 18);//set cursor position
		pGlobalParameters->pCommands->Color(Set[0]);
		cout << "1. Start Game";

		pGlobalParameters->pCommands->GoToXY(10, 19);
		pGlobalParameters->pCommands->Color(Set[1]);
		cout << "2. Options";

		pGlobalParameters->pCommands->GoToXY(10, 20);
		pGlobalParameters->pCommands->Color(Set[2]);
		cout << "3. Help";

		pGlobalParameters->pCommands->GoToXY(10, 21);
		pGlobalParameters->pCommands->Color(Set[3]);
		cout << "4. Exit";
		pGlobalParameters->pCommands->Color(7);

		pGlobalParameters->pCommands->GoToXY(10, 23);
		pGlobalParameters->pCommands->Color(7);
		cout << "Use the arrow keys to navigate and";

		pGlobalParameters->pCommands->GoToXY(10, 24);
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
				pGlobalParameters->pCommands->GoToXY(10, 22);
				pGlobalParameters->pCommands->ClearCurrentLine();
				cout << "START GAME" << "\r" << endl;
				pGlobalParameters->pHeroCreationMenu->StartHeroCreation(pGlobalParameters->pHeroClass, pGlobalParameters->pCommands);
				break;
			}
			else if (_menuPoint == 2)
			{
				//help
				pGlobalParameters->pCommands->GoToXY(10, 22);
				pGlobalParameters->pCommands->ClearCurrentLine();
				cout << "OPTIONS" << "\r" << endl;
				DisplayOptions(pGlobalParameters);
				break;
			}
			else if (_menuPoint == 3)
			{
				//help
				pGlobalParameters->pCommands->ClearLine(22);
				pGlobalParameters->pCommands->GoToXY(10, 22);
				cout << "USE ARROW KEYS AND ENTER TO SELECT" << "\r" << endl;
				continue;
			}
			else if (_menuPoint == 4)
			{
				pGlobalParameters->pCommands->ClearLine(22);
				pGlobalParameters->pCommands->GoToXY(10, 22);
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

void MainMenu::DisplayOptions(GlobalParameters* pGlobalParameters)
{
	int i = 1;
	int counter = 1;
	int Set[] = { 12,7 };	// 7 = white , 12 = red
	char key;

	system("cls");
	pGlobalParameters->pCommands->GoToXY(0,0);
	pGlobalParameters->pArtwork->Options();
	pGlobalParameters->pCommands->GoToXY(10, 7);//set cursor position
	pGlobalParameters->pCommands->Color(Set[1]);
	cout << "Options";

	for (i = 1;;)
	{

		pGlobalParameters->pCommands->GoToXY(10, 9);
		pGlobalParameters->pCommands->Color(Set[0]);
		cout << "1. Sound";

		pGlobalParameters->pCommands->GoToXY(10, 10);
		pGlobalParameters->pCommands->Color(Set[1]);
		cout << "2. Back";



		key = _getch();		// reads a single character from the keyboard without echoing it to the console.

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
				if (pGlobalParameters->pMusicThread != nullptr)
				{
					switch (*pGlobalParameters->pMusicIsPlaying)
					{
					case true:
						PlaySound(NULL, NULL, 0);
						pGlobalParameters->pMusicThread ->~thread();
						*pGlobalParameters->pMusicIsPlaying = false;
						pGlobalParameters->pCommands->GoToXY(20,9);
						cout << " Off "<<endl;
						break;
					case false:
						wchar_t wstr[] = L"music.wav";
						if (pGlobalParameters->pMusicThread != nullptr) { delete pGlobalParameters->pMusicThread; pGlobalParameters->pMusicThread = nullptr; };
						if (pGlobalParameters->pMusicThread == nullptr) { pGlobalParameters->pCommands->StartThreadedBackgroundMusic(pGlobalParameters->pMusicIsPlaying, pGlobalParameters->pMusicThread); }//creating new thread and detach(called in method) it!
						*pGlobalParameters->pMusicIsPlaying = true;
						pGlobalParameters->pCommands->GoToXY(20, 9);
						cout << "  ON" << endl;
						break;
					}
				}
				continue;
			}
			else if (counter == 2)
			{
				pGlobalParameters->pCommands->Color(7);
				system("cls");
				pGlobalParameters->pMainMenu->StartMenu(pGlobalParameters);
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