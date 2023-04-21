#pragma once
#include <thread>
//#include "Commands.h"
#include "Artwork.h"
//#include "HeroClass.h"
#include "HeroCreationMenu.h"

class MainMenu
{
public:
	void StartMenu(
		Commands* const pCommands, 
		Artwork* const pArtwork, 
		std::thread* pMusicThread, 
		MainMenu* const pMainMenu,
		bool* pMusicIsPlaying,
		HeroClass* pHeroClass, 
		HeroCreationMenu* pHeroCreationMenu, 
		bool _isPlaying);
private:
	void DisplayOptions
	(
		Commands* const pCommands, 
		Artwork* const pArtwork, 
		std::thread* pMusicThread, 
		MainMenu* const pMainMenu, 
		bool* pMusicIsPlaying, 
		HeroClass* pHeroClass, 
		HeroCreationMenu* pHeroCreationMenu,
		bool _isPlaying
	);
};

