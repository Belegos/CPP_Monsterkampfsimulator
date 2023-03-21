#pragma once
class MainMenu
{
public:
	void StartMenu();
	int PlayerChoise{};
private:
	void Color(int color);
	void GoToXY(int x, int y);
	void ClearLine(int y);
	void ClearCurrentLine();
};

