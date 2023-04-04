#pragma once
#include <iostream>
#include <Windows.h>
#include <thread>
#include <mmsystem.h>
#include "MainMenu.h"
#include "Commands.h"
#include "Artwork.h"
#include "HeroClass.h"
#include "HeroCreationMenu.h"

class GlobalParameters
{
public:
	std::shared_ptr<Artwork> pArtwork{ nullptr };
	std::shared_ptr<Commands> pCommands{ nullptr };
	std::shared_ptr<bool> pMusicIsPlaying{ nullptr };

	MainMenu* pMainMenu;
	std::shared_ptr<HeroClass> pHeroClass{ nullptr };
	std::shared_ptr<HeroCreationMenu> pHeroCreationMenu{ nullptr };

	//Artwork* pArtwork{ nullptr };
	//Commands* pCommands{ nullptr };
	//bool* pMusicIsPlaying{ nullptr };
	//std::thread* pMusicThread{ nullptr };
	//HeroClass* pHeroClass{ nullptr };
	//HeroCreationMenu* pHeroCreationMenu{ nullptr };
	void InitGlobalParameters(std::thread* pMusicThread);
};
