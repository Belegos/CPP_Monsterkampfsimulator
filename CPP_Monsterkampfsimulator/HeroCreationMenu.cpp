#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "HeroCreationMenu.h"
#include "HeroClass.h"

void HeroCreationMenu::increaseFunction(Commands* const pCommands, int _selectedHeroAttribute, int m_maximumAttributes,
	int m_minimumAttributes, int* m_currentAttributes[], char m_input)
{
	int Set[] = { 12,7,7,7 };	// 7 = white , 12 = red
	int _menuPoint = 1;
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
		pCommands->GoToXY(0, 10);
		pCommands->Color(Set[1]);
		std::cout << "Attack: " << _heroAttributes[1] << std::endl;
		pCommands->GoToXY(0,11);
		pCommands->Color(Set[2]);
		std::cout << "Defense: " << _heroAttributes[2] << std::endl;
		pCommands->GoToXY(0, 12);
		pCommands->Color(Set[3]);
		std::cout << "Speed: " << _heroAttributes[3] << std::endl;
		pCommands->Color(Set[1]);

		m_input = _getch();

		if (m_input == 80 && (_menuPoint >= 1 && _menuPoint <= 3))//arrowkey down
		{
			_menuPoint++;
			_selectedHeroAttribute++;
		}
		if (m_input == 72 && (_menuPoint >= 2 && _menuPoint <= 4))//arrowkey up
		{
			_menuPoint--;
			_selectedHeroAttribute--;
		}

		if (m_input == 75)//arrowkey left
		{
			if (_AttributePoints > 0)
			{
				m_currentAttributes[_selectedHeroAttribute]--;
				_heroAttributes[_selectedHeroAttribute]--;
				_AttributePoints++;
			}
		}
		if (m_input == 77)//arrowkey right
		{
			if (_AttributePoints > 0)
			{
				m_currentAttributes[_selectedHeroAttribute]++;
				_heroAttributes[_selectedHeroAttribute]++;
				_AttributePoints--;
			}
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

void HeroCreationMenu::StartHeroCreation(HeroClass* const pHeroClass, Commands* const pCommands)
{
	int _heroHealth = pHeroClass->ModifyHealth() + 1;
	int _heroAttack = pHeroClass->GetAttack() + 1;
	int _heroDefense = pHeroClass->GetDefense() + 1;
	int _heroSpeed = pHeroClass->GetSpeed() + 1;
	int _heroAttributes[] = { _heroHealth, _heroAttack, _heroDefense, _heroSpeed };
	int _selectedHeroAttribute{ 0 };
	int* pHeroAttributes[] = { &_heroHealth, &_heroAttack, &_heroDefense, &_heroSpeed };

	increaseFunction(pCommands, _selectedHeroAttribute, _maximumAttributes, _minAttributes, pHeroAttributes, key);
}