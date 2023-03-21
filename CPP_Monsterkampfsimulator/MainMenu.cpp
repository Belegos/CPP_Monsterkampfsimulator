#include "MainMenu.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void MainMenu::StartMenu()
{
	int Set[] = { 7,7,7 };	// 7 = white
	int counter = 2;
	char key;

	for (int i = 0;;)
	{
		key = _getch();		//get key pressed by user
		GoToXY(10, 5);		//set cursor position
		Color(Set[0]);
		cout << "1. Start Game";

		GoToXY(10, 6);
		Color(Set[1]);
		cout << "2. Help";

		GoToXY(10, 7);
		Color(Set[2]);
		cout << "3. Exit";

		if (key == 80 && (counter >= 1 && counter <= 2))		//if key pressed is down arrow
		{
			counter++;
		}
		else if (key == 72 && (counter >= 2 && counter <=3))	//if key pressed is up arrow
		{
			counter--;
		}
		else if (key == 13)	//if key pressed is enter
		{
			if (counter == 0)
			{
				//start game
				cout << "START GAME";
			}
			else if (counter == 1)
			{
				//help
				cout << "HELP";
			}
			else if (counter == 2)
			{
				//exit
				cout << "EXIT";
			}
		}

		Set[0] = 7; //color.white (default)
		Set[1] = 7;
		Set[2] = 7;

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
		}
	}
}

void MainMenu::Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void MainMenu::GoToXY(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);// Set Console Cursor Position
}