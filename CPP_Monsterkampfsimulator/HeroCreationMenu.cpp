#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "HeroCreationMenu.h"
#include "HeroClass.h"

void HeroCreationMenu::StartHeroCreation(HeroClass* const pHeroClass) 
{
	//menu with arrowkey input up and down for choosing attributes
	//menu with arrowkey input left and right for decreasing or increasing attributes
	// 5.th menu point to confirm hero creation, if all attributes are set are withing the limit
	// Warning if attribute points are left, with confirmation and go back
	// 6.th menu point to go back to main menu

	int _maximumAttributes = 200;
	int _attributePoints = 200;

	int _heroHealth = pHeroClass->GetHealth()+1;//give all attributes at least 1 point
	int _heroAttack = pHeroClass->GetAttack()+1;
	int _heroDefense = pHeroClass->GetDefense()+1;
	int _heroSpeed = pHeroClass->GetSpeed()+1;


}