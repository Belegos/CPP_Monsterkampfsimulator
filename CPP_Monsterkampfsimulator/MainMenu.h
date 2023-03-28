#pragma once
#include <thread>
#include "Commands.h"
#include "Artwork.h"
class MainMenu
{
public:
	void StartMenu(Commands* const pCommands, Artwork* const pArtwork, std::thread* const pMusicThread, MainMenu* const pMainMenu);
private:
	void DisplayOptions(Commands* const pCommands, Artwork* const pArtwork, std::thread* const pMusicThread, MainMenu* const pMainMenu);
};

