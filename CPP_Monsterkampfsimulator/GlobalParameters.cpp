#pragma once
#include "GlobalParameters.h"
#pragma comment(lib, "winmm.lib")


void GlobalParameters::InitGlobalParameters(std::thread* pMusicThread)
{
	pCommands = std::make_shared<Commands>();
	pArtwork = std::make_shared<Artwork>();
	pMusicIsPlaying = std::make_shared<bool>(true);
	pHeroClass = std::make_shared<HeroClass>();
	pHeroCreationMenu = std::make_shared<HeroCreationMenu>();
	pCommands->StartThreadedBackgroundMusic(&*pMusicIsPlaying, pMusicThread);


	//pMainMenu = new MainMenu();
	//pCommands = new Commands();
	//pArtwork = new Artwork();
	//pMusicIsPlaying = new bool{ true };
	//pHeroClass = new HeroClass();
	//pHeroCreationMenu = new HeroCreationMenu();
	//pCommands->StartThreadedBackgroundMusic(pMusicIsPlaying,pMusicThread);
}
