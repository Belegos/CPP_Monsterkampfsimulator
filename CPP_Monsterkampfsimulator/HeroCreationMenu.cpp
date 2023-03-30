#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "HeroCreationMenu.h"
#include "HeroClass.h"

void HeroCreationMenu::increaseFunction(int pFunc_mValue, int index, int m_maximumAttributes,
    int m_minimumAttributes, int* m_currentAttriebutes[], char m_input)
{
    while (_AttributePoints != 0)
    {
        m_input = _getch();

        if (m_input == 72 && index > 0 && index < 4)//arrowkey up
        {
            index--;
        }
        if (m_input == 80 && index >= 0 && index < 3)//arrowkey down
        {
            index++;
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
    }
}

void HeroCreationMenu::StartHeroCreation(HeroClass* const pHeroClass)
{
    int _heroHealth = pHeroClass->GetHealth() + 1;
    int _heroAttack = pHeroClass->GetAttack() + 1;
    int _heroDefense = pHeroClass->GetDefense() + 1;
    int _heroSpeed = pHeroClass->GetSpeed() + 1;
    int _heroAttributes[4] = { _heroHealth, _heroAttack, _heroDefense, _heroSpeed };
    int index{ 0 };
    int* pHeroAttributes[4] = { &_heroHealth, &_heroAttack, &_heroDefense, &_heroSpeed };

    increaseFunction(1, index, _maximumAttributes, _minAttributes, pHeroAttributes, key);
}