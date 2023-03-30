#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <thread>
#include "Commands.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

/// <summary>
/// The "Color" function changes the color of the console text
/// </summary>
/// <param name="color"></param>
void Commands::Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/// <summary>
/// The "GoToXY" function sets the cursor position on the console
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Commands::GoToXY(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);// Set Console Cursor Position
}
/// <summary>
/// Simple cout to clear a line in console.
/// </summary>
/// <param name="y = Number of line to clear"></param>
void Commands::ClearLine(int y)
{
	GoToXY(0, y);
	for (int i = 0; i < 80; i++)
	{
		cout << " ";
	}
	GoToXY(0, y);
}
/// <summary>
/// The method clears the current line in the console 
/// by outputting the escape sequence "\x1b[2K", 
/// which clears the line from the current cursor 
/// position to the end of the line.
/// </summary>
void Commands::ClearCurrentLine()
{
	std::cout << "\x1b[2K";
}

//MultiThreading
void Commands::playBackgroundMusic()
{
	const wchar_t wstr[] = L"music.wav";
	PlaySound(wstr, NULL, SND_ASYNC | SND_LOOP);
}


void Commands::StartThreadedBackgroundMusic(bool* pMusicIsPlaying, std::thread*& pMusicThread)&
{
	pMusicThread = new std::thread(&Commands::playBackgroundMusic,this);
	*pMusicIsPlaying = true;
	pMusicThread->detach();
}