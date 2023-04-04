#pragma once
#include "GlobalParameters.h"

class MainMenu
{
public:
	void StartMenu(GlobalParameters pGlobalParameters, std::thread* pMusicThread);
private:
	void DisplayOptions(GlobalParameters pGlobalParameters, std::thread* pMusicThread);
};

