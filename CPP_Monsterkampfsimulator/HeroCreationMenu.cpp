#include "HeroCreationMenu.h"

/// <summary>
/// 
/// </summary>
/// <param name="pHeroClass"></param>
/// <param name="pCommands"></param>
void HeroCreationMenu::StartHeroCreation(HeroClass* const pHeroClass, Commands* const pCommands)
{
	int _heroAttributes[] = { pHeroClass->ModifyHealth(1), pHeroClass->ModifyAttack(1), pHeroClass->ModifyDefense(1), pHeroClass->ModifySpeed(1) };
	int _selectedHeroAttribute{ 0 };//index to navigate
	int* pHeroAttributes[] = { &_heroAttributes[1],&_heroAttributes[2],&_heroAttributes[3],&_heroAttributes[4] };

	increaseFunction(pCommands, _selectedHeroAttribute, _maxAttributes, _minAttributes, pHeroAttributes, key, pHeroClass);
}

/// <summary>
/// 
/// </summary>
/// <param name="pCommands"></param>
/// <param name="_selectedHeroAttribute"></param>
/// <param name="m_maximumAttributes"></param>
/// <param name="m_minimumAttributes"></param>
/// <param name="m_currentAttributes"></param>
/// <param name="m_input"></param>
void HeroCreationMenu::increaseFunction(Commands* const pCommands, int _selectedHeroAttribute, int m_maximumAttributes,
	int m_minimumAttributes, int* m_currentAttributes[], char m_input, HeroClass* pHeroClass)
{
	int Set[6] = { 12,7,7,7,7,12 };	// 7 = white , 12 = red
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

		DisplayLeftAttributePoints(pCommands);

		DisplayCurrentAttributes(pCommands, Set, _heroAttributesNames);

		m_input = _getch();

		MenuNavigationUpAndDown(pCommands, m_input, _menuPoint, _selectedHeroAttribute);

		if (m_input == 75)//arrowkey left
		{
			if (_heroAttributes[_selectedHeroAttribute] > 0 && _AttributePoints < _maxAttributes)
			{
				m_currentAttributes[_selectedHeroAttribute]--;
				_heroAttributes[_selectedHeroAttribute]--;
				_AttributePoints++;
			}
		}
		if (m_input == 77)//arrowkey right
		{
			if (_heroAttributes[_selectedHeroAttribute] < _maxAttributes - 3 && _AttributePoints>_minAttributes)
			{
				m_currentAttributes[_selectedHeroAttribute]++;
				_heroAttributes[_selectedHeroAttribute]++;
				_AttributePoints--;
			}
		}
		if (m_input == 8)//backspace 
		{
			//TODO: go back to MainMenu
			//TODO: create class to store important pointer for menu obj and other important global var's.
			break;
			//pMainMenu->StartMenu(pCommands, pArtwork, pMusicThread, pMainMenu, pMusicIsPlaying, pHeroClass, pHeroCreationMenu);
		}
		if (m_input == 13)
		{
			if (_AttributePoints >= 1)
			{
				//Displays error message, if not all attributes are spent
				pCommands->ClearLine(15);
				pCommands->ClearLine(16);
				pCommands->GoToXY(0, 17);
				pCommands->Color(Set[5]);
				std::cout << "Please spend all attribute points." << std::endl;
				std::cout << "Please edit your values and try again." << std::endl;
				pCommands->Color(Set[4]);
				_errorDisplayed = true;
			}
			if (_heroAttributes[0] == 0 || _heroAttributes[1] == 0 || _heroAttributes[2] == 0 || _heroAttributes[3] == 0)
			{
				//Displays error message, if not all attributes are at least 1
				pCommands->GoToXY(0, 15);
				pCommands->Color(Set[5]);
				std::cout << "All attributes should have at least the value 1" << std::endl;
				std::cout << "Please edit your values and try again." << std::endl;
				pCommands->Color(Set[4]);
				_errorDisplayed = true;
			}
			else if (_AttributePoints == 0 && _heroAttributes[0] > 0 && _heroAttributes[1] > 0 && _heroAttributes[2] > 0 && _heroAttributes[3] > 0)
			{
				system("cls");
				pCommands->GoToXY(0, 0);
				//TODO: Start HeroFight!
				std::shared_ptr<FightingClass> _fight = std::make_shared<FightingClass>();
				_fight->InitFight(pCommands,pHeroClass);

				break;
			}
		}
		//Set Colors of text back to default case.
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;
		Set[5] = 12;

		switch (_menuPoint)//switchacase to color the choosen menuPoint in red.
		{
		case 1:
			Set[0] = 12;
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
/// <summary>
/// Simple method to navigate in the attributes of the hero. 
/// Delete displayed error message, if not all requirement of the herocreation are checked
/// </summary>
/// <param name="pCommands">Insert the commands class object for important commands in this programm</param>
/// <param name="m_input">Insert a valid char for input handling</param>
/// <param name="_menuPoint">Indexer of the _selectedHeroAttributeArray</param>
/// <param name="_selectedHeroAttribute">Array of Attributes for the hero</param>
void HeroCreationMenu::MenuNavigationUpAndDown(Commands* const& pCommands, char m_input, int& _menuPoint, int& _selectedHeroAttribute)
{
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
	if (_errorDisplayed = true && (m_input == 72 || m_input == 80))
	{
		for (int i = 15; i < 19; i++)
		{
			pCommands->ClearLine(i);
		}
		_errorDisplayed = false;
	}

}
/// <summary>
/// 
/// </summary>
/// <param name="pCommands">Insert the commands class object for important commands in this programm</param>
void HeroCreationMenu::DisplayLeftAttributePoints(Commands* const& pCommands)
{
	pCommands->GoToXY(0, 8);
	pCommands->ClearCurrentLine();
	pCommands->Color(7);
	printf("Attribute points: %d\n", _AttributePoints);
	pCommands->GoToXY(0, 9);
}
/// <summary>
/// 
/// </summary>
/// <param name="pCommands">Insert the commands class object for important commands in this programm</param>
/// <param name="Set"></param>
/// <param name="_heroAttributesNames"></param>
void HeroCreationMenu::DisplayCurrentAttributes(Commands* const& pCommands, int  Set[6], std::array<std::string, 4> _heroAttributesNames)
{
	int i = 0; //local int for navigation except the string array 

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
