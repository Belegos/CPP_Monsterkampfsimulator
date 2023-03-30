#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "HeroCreationMenu.h"
#include "HeroClass.h"

int HeroCreationMenu::increaseFunction(int fun_mValue, int m_maximumAttributes,
	int m_minimumAttributes, int m_currentAttriebutes[], char m_input)
{
	// fun_mValue -> the new amount of attribute points
	// m_maximumAttributes -> the maximum amount of attribute points
	// m_minimumAttributes -> the minimum amount of attribute points
	// m_currentAttriebutes -> the current selected attribute in the array of attributes
	// m_input -> the input from the keyboard
	while (_AttributePoints != 0)
	{
		m_input = _getch();

		if (m_input = 72 && index >= 0 && index < 3)//arrowkey up
		{
			index++;
		}
		if (m_input = 80 && index <= 3 && index > 0)//arrowkey down
		{
			index--;
		}

		if (m_input == 75)//arrowkey left
		{
			if (m_currentAttriebutes[index])
			{

			}
		}
		if (m_input == 77)//arrowkey right
		{
			if (m_currentAttriebutes[index])
			{

			}
		}
		if (m_input == 13 && m_currentAttriebutes > 0)//enterkey
		{

		}
		return m_currentAttriebutes[fun_mValue];
	}
}

void HeroCreationMenu::StartHeroCreation(HeroClass* const pHeroClass)
{
	//menu with arrowkey input up and down for choosing attributes
	//menu with arrowkey input left and right for decreasing or increasing attributes
	// 5.th menu point to confirm hero creation, if all attributes are set are withing the limit
	// Warning if attribute points are left, with confirmation and go back
	// 6.th menu point to go back to main menu

	int _heroHealth = pHeroClass->GetHealth() + 1;//give all attributes at least 1 point
	int _heroAttack = pHeroClass->GetAttack() + 1;
	int _heroDefense = pHeroClass->GetDefense() + 1;
	int _heroSpeed = pHeroClass->GetSpeed() + 1;
	int _heroAttributes[4] = { _heroHealth, _heroAttack, _heroDefense, _heroSpeed };

	auto value = pFunc_mValue(1, _maximumAttributes, _minAttributes, _heroAttributes[index], key);

}
