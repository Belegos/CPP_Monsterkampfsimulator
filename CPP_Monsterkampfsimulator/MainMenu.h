#pragma once
#include <thread>
#include "Commands.h"
#include "Artwork.h"
class MainMenu
{
public:
	void StartMenu(Commands* const pCommands, Artwork* const pArtwork, std::thread* pMusicThread, MainMenu* const pMainMenu,bool _musicIsPlaying);
private:
	void DisplayOptions(Commands* const pCommands, Artwork* const pArtwork, std::thread* pMusicThread, MainMenu* const pMainMenu, bool _musicIsPlaying);
	void PlayBackgroundMusic()&;
};

