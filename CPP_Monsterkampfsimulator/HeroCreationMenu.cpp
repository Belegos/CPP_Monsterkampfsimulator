#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <array>
#include "HeroCreationMenu.h"
#include "HeroClass.h"
void HeroCreationMenu::StartHeroCreation(HeroClass* const pHeroClass, Commands* const pCommands)
{
	int _heroAttributes[] = { pHeroClass->ModifyHealth(1), pHeroClass->ModifyAttack(1), pHeroClass->ModifyDefense(1), pHeroClass->ModifySpeed(1) };
	int _selectedHeroAttribute{ 0 };
	int* pHeroAttributes[] = { &_heroAttributes[1],&_heroAttributes[2],&_heroAttributes[3],&_heroAttributes[4] };

	increaseFunction(pCommands, _selectedHeroAttribute, _maxAttributes, _minAttributes, pHeroAttributes, key);
}
int HeroCreationMenu::ReturnAttributePoints()
{
	return _AttributePoints;
}
void HeroCreationMenu::increaseFunction(Commands* const pCommands, int _selectedHeroAttribute, int m_maximumAttributes,
	int m_minimumAttributes, int* m_currentAttributes[], char m_input)
{
	int Set[] = { 12,7,7,7,7 };	// 7 = white , 12 = red
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
		std::cout << "Press enter to continue if attributes are zero" << std::endl;
		std::cout << "----------------------" << std::endl;

		pCommands->GoToXY(0, 8);
		pCommands->ClearCurrentLine();
		pCommands->Color(7);
		printf("Attribute points: %d\n", _AttributePoints);
		pCommands->GoToXY(0, 9);


		DisplayCurrentAttributes(pCommands, Set, _heroAttributesNames);

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
			if (_heroAttributes[_selectedHeroAttribute] > 0 && _AttributePoints < 130)
			{
				m_currentAttributes[_selectedHeroAttribute]--;
				_heroAttributes[_selectedHeroAttribute]--;
				_AttributePoints++;
			}
		}
		if (m_input == 77)//arrowkey right
		{
			if (_heroAttributes[_selectedHeroAttribute] < _maxAttributes - 3 && _AttributePoints>0)
			{
				m_currentAttributes[_selectedHeroAttribute]++;
				_heroAttributes[_selectedHeroAttribute]++;
				_AttributePoints--;
			}
		}
		if (m_input == 13 && _AttributePoints == 0)
		{
			//TODO: start Combat with the created hero

			break;
		}
		Set[0] = 7; //color.white (default)
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;

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

void HeroCreationMenu::DisplayCurrentAttributes(Commands* const& pCommands, int  Set[5], std::array<std::string, 4> _heroAttributesNames)
{
	int i = 0;
	for (const auto& attribute : _heroAttributesNames) 
	{
		pCommands->GoToXY(0, 9 + i);
		pCommands->ClearCurrentLine();
		pCommands->Color(Set[i]);
		std::cout << attribute << ": " << _heroAttributes[i] << std::endl;
		pCommands->Color(Set[4]);
		i++;
		index++;
	}
}
