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
	Artwork* pArtwork{ nullptr };
	Commands* pCommands{ nullptr };
	MainMenu* pMainMenu{ nullptr };
	bool* pMusicIsPlaying{ nullptr };
	std::thread* pMusicThread{ nullptr };
	HeroClass* pHeroClass{ nullptr };
	HeroCreationMenu* pHeroCreationMenu{ nullptr };
	void InitGlobalParameters();
};
