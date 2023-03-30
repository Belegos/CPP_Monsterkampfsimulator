#pragma once
#include "HeroClass.h"
class HeroCreationMenu
{
public:
	void StartHeroCreation(HeroClass* const pHeroClass);
private:
	void increaseFunction(int pFunc_mValue, int index, int m_maximumAttributes,
		int m_minimumAttributes, int* m_currentAttriebutes[], char m_input);
	char key{}; //key input
	int _maximumAttributes = 200; //maximum amount of attribute points
	int _AttributePoints = 200; //amount of attribute points to spent
	int _minAttributes = 1; //minimum amount of attribute points for each attribute
	int _heroAttributes[4]; //array for the attributes
	int index{};
};

