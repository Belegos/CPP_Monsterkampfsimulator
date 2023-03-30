#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "HeroCreationMenu.h"
#include "HeroClass.h"

void HeroCreationMenu::increaseFunction(Commands* const pCommands, int index, int m_maximumAttributes,
	int m_minimumAttributes, int* m_currentAttriebutes[], char m_input)
{
	int Set[] = { 12,7,7,7 };	// 7 = white , 12 = red
	int counter = 1;
	system("cls");
	for (int i = 1;;)
	{
		pCommands->GoToXY(0, 0);
		pCommands->Color(7);
		std::cout << "Choose your attributes" << std::endl;
		std::cout << "----------------------" << std::endl;
		std::cout << "Use the arrow keys to navigate" << std::endl;
		std::cout << "Use the left and right arrow keys to increase or decrease the attributes" << std::endl;
		std::cout << "----------------------" << std::endl;
		std::cout << "Press enter to continue" << std::endl;
		std::cout << "----------------------" << std::endl;

		pCommands->GoToXY(0, 8);
		pCommands->Color(7);
		std::cout << "Attribute points: " << _AttributePoints << std::endl;

		pCommands->GoToXY(0, 9);
		pCommands->Color(Set[0]);
		std::cout << "Health: " << _heroAttributes[0] << std::endl;

		std::cout << "Attack: " << _heroAttributes[1] << std::endl;
		
		std::cout << "Defense: " << _heroAttributes[2] << std::endl;
		
		std::cout << "Speed: " << _heroAttributes[3] << std::endl;

		m_input = _getch();

		if (m_input == 72 && (counter >= 1 && counter <= 3))//arrowkey up
		{
			counter--;
		}
		if (m_input == 80 && (counter >= 2 && counter <= 4))//arrowkey down
		{
			counter++;
		}

		if (m_input == 75)//arrowkey left
		{
			if (*m_currentAttriebutes[index] > m_minimumAttributes && _AttributePoints > 0)
			{
				(*m_currentAttriebutes[index])--;
				_AttributePoints--;
			}
		}
		if (m_input == 77)//arrowkey right
		{
			if (_AttributePoints > 0 && (*m_currentAttriebutes[index]) < m_maximumAttributes)
			{
				(*m_currentAttriebutes[index])++;
				_AttributePoints--;
			}
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

void HeroCreationMenu::StartHeroCreation(HeroClass* const pHeroClass, Commands* const pCommands)
{
	int _heroHealth = pHeroClass->GetHealth() + 1;
	int _heroAttack = pHeroClass->GetAttack() + 1;
	int _heroDefense = pHeroClass->GetDefense() + 1;
	int _heroSpeed = pHeroClass->GetSpeed() + 1;
	int _heroAttributes[4] = { _heroHealth, _heroAttack, _heroDefense, _heroSpeed };
	int index{ 0 };
	int* pHeroAttributes[4] = { &_heroHealth, &_heroAttack, &_heroDefense, &_heroSpeed };

	increaseFunction(pCommands, index, _maximumAttributes, _minAttributes, pHeroAttributes, key);
}