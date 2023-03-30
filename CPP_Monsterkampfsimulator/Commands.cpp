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
/// The "Color" function changes the color of the console text.
/// Int 7 for white and Int 12 for red, as example.
/// </summary>
/// <param name="color">Color as an Int</param>
void Commands::Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/// <summary>
/// The "GoToXY" function sets the cursor position on the console
/// </summary>
/// <param name="x">X-Position in Console</param>
/// <param name="y">Y-Position in Console</param>
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
/// <summary>
/// This C++ code defines a member function called "playBackgroundMusic" within the class "Commands".
/// The function is responsible for playing a background music track. It uses the "PlaySound" function to play a sound file with the specified name in a separate thread.
/// The sound file name is hardcoded as a wide character string, "music.wav". The function uses the flags "SND_ASYNC" and "SND_LOOP" to play the sound asynchronously and continuously in a loop, respectively.
/// </summary>
void Commands::playBackgroundMusic()
{
	const wchar_t wstr[] = L"music.wav";
	PlaySound(wstr, NULL, SND_ASYNC | SND_LOOP);
}

/// <summary>
/// This C++ code defines a member function called "StartThreadedBackgroundMusic" within the class "Commands".
/// The function takes in a boolean pointer "pMusicIsPlaying" and a pointer to a std::thread object "pMusicThread" as parameters.
/// The purpose of this function is to start playing background music in a separate thread, and update the 
/// "pMusicIsPlaying" boolean flag to indicate that the music is now playing.
/// A new std::thread object is created using the "playBackgroundMusic" member function of the "Commands" class, 
/// and the "pMusicIsPlaying" flag is set to true.
/// Finally, the newly created thread is detached from the main thread using the "detach" function.
/// </summary>
/// <param name="pMusicIsPlaying">A boolean pointer indicating whether the background music is playing or not.</param>
/// <param name="pMusicThread">A pointer to a std::thread object used to play the background music in a separate thread.</param>
void Commands::StartThreadedBackgroundMusic(bool* pMusicIsPlaying, std::thread*& pMusicThread)&
{
	pMusicThread = new std::thread(&Commands::playBackgroundMusic,this);
	*pMusicIsPlaying = true;
	pMusicThread->detach();
}