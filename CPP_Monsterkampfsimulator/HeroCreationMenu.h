#pragma once
#include "HeroClass.h"
class HeroCreationMenu
{
public:
	void StartHeroCreation(HeroClass* const pHeroClass);
private:
	char key{}; //key input
	int _maximumAttributes = 200; //maximum amount of attribute points
	int _AttributePoints = 200; //amount of attribute points to spent
	int _minAttributes = 1; //minimum amount of attribute points for each attribute
	int _heroAttributes[4]; //array for the attributes
	int index;
	int(*pFunc_mValue)(int,int,int,int,char);
	int increaseFunction(int pFunc_mValue, int m_maximumAttributes,
		int m_minAttributes, int m_currentAttributes[], char m_inputChar);
};

