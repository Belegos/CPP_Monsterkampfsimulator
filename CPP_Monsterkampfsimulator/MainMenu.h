#pragma once
#include "Commands.h"
#include "Artwork.h"
class MainMenu
{
public:
	void StartMenu(Commands* const pCommands, Artwork* const pArtwork);
private:
	void DisplayOptions(Commands* const pCommands, Artwork* const pArtwork);
};

