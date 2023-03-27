#pragma once
class Commands
{
public:
//Console
	void Color(int color);
	void GoToXY(int x, int y);
	void ClearLine(int y);
	void ClearCurrentLine();
private:

//Music
public:
	void StartThreadedBackgroundMusic();
private:
	void playBackgroundMusic();
};

