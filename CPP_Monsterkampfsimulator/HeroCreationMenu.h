#pragma once
#include "HeroClass.h"
#include "Commands.h"
#include <iostream>
#include <string>
#include <array>
class HeroCreationMenu
{
public:
	void StartHeroCreation(HeroClass* const pHeroClass,Commands* const pCommands);
private:
	void increaseFunction(Commands* const pCommands, int index, int m_maximumAttributes,
		int m_minimumAttributes, int* m_currentAttriebutes[], char m_input);
	void MenuNavigationUpAndDown(Commands* const& pCommands,char m_input, int& _menuPoint, int& _selectedHeroAttribute);
	void DisplayLeftAttributePoints(Commands* const& pCommands);
	void DisplayCurrentAttributes(Commands* const& pCommands, int  Set[5], std::array<std::string,4> _heroAttributesNames);
	char key{}; //key input
	int _maxAttributes{ 100 }; //maximum amount of attribute points
	int _AttributePoints{ _maxAttributes }; //amount of attribute points to spent
	int _minAttributes = 0; //minimum amount of attribute points for each attribute
	int _heroAttributes[4]; //array for the attributes
	int index{};
	bool _errorDisplayed{ false };
	std::array<std::string, 4> _heroAttributesNames = { "Health","Attack","Defense","Speed" };
};

