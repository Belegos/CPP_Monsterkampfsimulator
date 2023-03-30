#pragma once
#include <thread>
class Commands
{
public:
	//Console
	void Color(int color);
	void GoToXY(int x, int y);
	void ClearLine(int y);
	void ClearCurrentLine();
	//MultiThreading
	void playBackgroundMusic();
	void StartThreadedBackgroundMusic(bool* pMusicIsPlaying,std::thread*& pMusicThread)&;
};

