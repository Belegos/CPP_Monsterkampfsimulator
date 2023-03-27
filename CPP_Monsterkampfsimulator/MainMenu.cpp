#include <iostream>
#include "MainMenu.h"
#include "Artwork.h"
#include <conio.h>
using namespace std;

/// <summary>
/// The "StartMenu" function displays a menu with three options and
/// allows the user to navigate and select an option using arrow keys and the enter key. 
/// </summary>
void MainMenu::StartMenu(Commands& pCommands)
{
	int Set[] = { 12,7,7 };	// 7 = white , 12 = red
	int counter = 1;
	char key;
	Artwork art;

	for (int i = 1;;)
	{
		pCommands.GoToXY(0, 0);
		art.Title();
		pCommands.GoToXY(10, 18);//set cursor position
		pCommands.Color(Set[0]);
		cout << "1. Start Game";

		pCommands.GoToXY(10, 19);
		pCommands.Color(Set[1]);
		cout << "2. Help";

		pCommands.GoToXY(10, 20);
		pCommands.Color(Set[2]);
		cout << "3. Exit";
		pCommands.Color(7);

		pCommands.GoToXY(10, 22);
		pCommands.Color(7);
		cout << "Use the arrow keys to navigate and";
		pCommands.GoToXY(10, 23);
		cout << "the enter key to select an option." << endl;
		

		key = _getch();		// reads a single character from the keyboard without echoing it to the console.

		if (key == 80 && (counter >= 1 && counter <= 2))		//if key pressed is down arrow
		{
			counter++;
		}
		else if (key == 72 && (counter >= 2 && counter <= 3))	//if key pressed is up arrow
		{
			counter--;
		}
		else if (key == 13)	//if key pressed is enter
		{
			if (counter == 1)
			{
				//start game
				//ClearLine(9);
				pCommands.GoToXY(10, 21);
				pCommands.ClearCurrentLine();
				cout << "START GAME" << "\r" << endl;
				//break;
			}
			else if (counter == 2)
			{
				//help
				pCommands.ClearLine(21);
				pCommands.GoToXY(10, 21);
				cout << "HELP" << "\r" << endl;
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