#pragma once
#include "HeroClass.h"
class HeroCreationMenu
{
public:
	void StartHeroCreation(HeroClass* const pHeroClass);
	void IncreaseAttribute(HeroClass* const pHeroClass);
	void DecreaseAttribute(HeroClass* const pHeroClass);
private:
	char key{}; //key input
	int _maximumAttributes = 200; //maximum amount of attribute points
	int _attributePoints = 200; //amount of attribute points to spent
	int _minAttributePoints = 1; //minimum amount of attribute points for each attribute
};

