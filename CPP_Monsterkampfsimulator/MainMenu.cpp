#include "MainMenu.h"
#include <iostream>
#include <windows.h>
#include <conio.h> // non-standart c++ headerfile, for reading user input in windows 
using namespace std;
/// <summary>
/// The "StartMenu" function displays a menu with three options and
/// allows the user to navigate and select an option using arrow keys and the enter key. 
/// </summary>
void MainMenu::StartMenu()
{
	int Set[] = { 12,7,7 };	// 7 = white , 12 = red
	int counter = 1;
	char key;

	for (int i = 1;;)
	{
		GoToXY(10, 5);		//set cursor position
		Color(Set[0]);
		cout << "1. Start Game";

		GoToXY(10, 6);
		Color(Set[1]);
		cout << "2. Help";

		GoToXY(10, 7);
		Color(Set[2]);
		cout << "3. Exit";

		key = _getch();		// reads a single character from the keyboard without echoing it to the console.

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
			if (counter == 1)
			{
				//start game
				//ClearLine(9);
				GoToXY(10, 9);
				ClearCurrentLine();
				cout << "START GAME" << "\r"<<endl;
				//break;
			}
			else if (counter == 2)
			{
				//help
				ClearLine(9);
				GoToXY(10, 9);
				cout << "HELP" << "\r"<<endl;
				//break;
			}
			else if (counter == 3)
			{
				exit(0);
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
/// <summary>
/// The "Color" function changes the color of the console text
/// </summary>
/// <param name="color"></param>
void MainMenu::Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/// <summary>
/// The "GoToXY" function sets the cursor position on the console
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void MainMenu::GoToXY(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);// Set Console Cursor Position
}
/// <summary>
/// Simple cout to clear a line in console.
/// </summary>
/// <param name="y = Number of line to clear"></param>
void MainMenu::ClearLine(int y) 
{
	GoToXY(0, y);
	for (int i = 0; i < 80; i++) {
		cout << " ";
	}
	GoToXY(0, y);
}
void MainMenu::ClearCurrentLine() 
{
	std::cout << "\x1b[2K";
}