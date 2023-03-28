#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <thread>
#include <Windows.h>
#include <mmsystem.h>
#include "MainMenu.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

/// <summary>
/// The "StartMenu" function displays a menu with three options and
/// allows the user to navigate and select an option using arrow keys and the enter key. 
/// </summary>
void MainMenu::StartMenu(Commands* const pCommands, Artwork* const pArtwork, std::thread* const pMusicThread, MainMenu* const pMainMenu, bool _musicIsPlaying)// const = read only Pointer, to prevent creating a new obj on the pointer while using 
{
	int Set[] = { 12,7,7,7 };	// 7 = white , 12 = red
	int counter = 1;
	int counterTwo = 1;
	char key;

	pArtwork->Title();
	for (int i = 1;;)
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


		key = _getch();		// reads a single character from the keyboard without echoing it to the console.

		if (key == 80 && (counter >= 1 && counter <= 3))		//if key pressed is down arrow
		{
			counter++;
		}
		else if (key == 72 && (counter >= 2 && counter <= 4))	//if key pressed is up arrow
		{
			counter--;
		}
		else if (key == 13)	//if key pressed is enter
		{
			if (counter == 1)
			{
				//start game
				pCommands->GoToXY(10, 22);
				pCommands->ClearCurrentLine();
				cout << "START GAME" << "\r" << endl;
				//break;
			}
			else if (counter == 2)
			{
				//help
				pCommands->GoToXY(10, 22);
				pCommands->ClearCurrentLine();
				cout << "OPTIONS" << "\r" << endl;
				DisplayOptions(pCommands, pArtwork, pMusicThread, this, _musicIsPlaying);
				break;
			}
			else if (counter == 3)
			{
				//help
				pCommands->ClearLine(22);
				pCommands->GoToXY(10, 22);
				cout << "HELP" << "\r" << endl;
				continue;
			}
			else if (counter == 4)
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

		switch (counter)
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

void MainMenu::DisplayOptions(Commands* const pCommands, Artwork* const pArtwork, std::thread* pMusicThread, MainMenu* const pMainMenu, bool _musicIsPlaying)
{
	int i = 1;
	int counter = 1;
	int Set[] = { 12,7 };	// 7 = white , 12 = red
	char key;
	system("cls");
	pCommands->GoToXY(0, 0);
	pArtwork->Options();
	pCommands->GoToXY(10, 7);//set cursor position
	pCommands->Color(Set[1]);
	cout << "Options";
	for (i = 1;;)
	{

		pCommands->GoToXY(10, 9);
		pCommands->Color(Set[0]);
		cout << "1. Sound";

		pCommands->GoToXY(10, 10);
		pCommands->Color(Set[1]);
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
				//pCommands->Color(7);
				if (pMusicThread != nullptr)
				{
					switch (_musicIsPlaying)
					{
					case true:
						_musicIsPlaying = false;
						pMusicThread->join();
						PlaySound(NULL, NULL, 0);
						break;
					case false:
						wchar_t wstr[] = L"music.wav";
						if (pMusicThread != nullptr) { delete pMusicThread; pMusicThread = nullptr; };
						if (pMusicThread == nullptr) { pMusicThread = new std::thread(&MainMenu::PlayBackgroundMusic, this); }
						pMusicThread->detach();
						_musicIsPlaying = true;
						break;
					}
				}
				if (pMusicThread == nullptr)
				{
					continue;
				}
				continue;
			}
			else if (counter == 2)
			{
				//pCommands->GoToXY(10, 10);
				//pCommands->Color(12);
				//cout << "2. Back";
				pCommands->Color(7);
				system("cls");
				pMainMenu->StartMenu(pCommands, pArtwork, pMusicThread, pMainMenu, _musicIsPlaying);
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
void MainMenu::PlayBackgroundMusic()&
{
	wchar_t wstr[] = L"music.wav";
	PlaySound(wstr, NULL, SND_ASYNC | SND_LOOP);
}