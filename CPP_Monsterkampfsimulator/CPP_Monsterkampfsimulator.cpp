#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <thread>
#include "Commands.h"
#include "MainMenu.h"
#include "Artwork.h"
#include "Monster.h"
#include "MonsterFactory.h"
#include "HeroClass.h"
#include "HeroCreationMenu.h"
#pragma comment(lib, "winmm.lib")

using namespace std;

#pragma region templates
template<typename T>
void checkNullPtr(T*& pPointer)
{
	if (pPointer != nullptr) { pPointer = nullptr; }
	else {}
}
template<typename T>
void setPointerNullDeleteObject(T*& pPointer)
{
	if (pPointer == nullptr) {};
	if (pPointer != nullptr) { delete pPointer; };
	pPointer = nullptr;
}
#pragma endregion templates

#pragma region Forward_Declaration
bool* pMusicIsPlaying{ nullptr };
MainMenu* pMainMenu{ nullptr };
//StringifierClass* pStringifierClass{ nullptr };
Commands* pCommands{ nullptr };
Artwork* pArtwork{ nullptr };
std::thread* pMusicThread{ nullptr };
HeroCreationMenu* pHeroCreationMenu{ nullptr };
HeroClass* pHeroClass{ nullptr };
#pragma endregion Forward_Declaration

/// <summary>
/// Collection of Pointern, which are check if nullptr,
///  if not set to nullptr
/// </summary>
static void Init()
{
	checkNullPtr(pMusicIsPlaying);
	checkNullPtr(pMainMenu);
	//checkNullPtr(pStringifierClass);
	checkNullPtr(pCommands);
	checkNullPtr(pArtwork);
	checkNullPtr(pMusicThread);
	checkNullPtr(pHeroClass);
	checkNullPtr(pHeroCreationMenu);
}

int main()
{
	Init();

	pMainMenu = new MainMenu();
	//pStringifierClass = new StringifierClass();
	pCommands = new Commands();
	pArtwork = new Artwork();
	pMusicIsPlaying = new bool{ true };
	pHeroClass = new HeroClass();
	pHeroCreationMenu = new HeroCreationMenu();
	pCommands->StartThreadedBackgroundMusic(pMusicIsPlaying, pMusicThread);
	bool _isPlaying = true;


#pragma region startMainLoop
	while (_isPlaying)
	{
		pMainMenu->StartMenu(pCommands, pArtwork, pMusicThread, pMainMenu, pMusicIsPlaying, pHeroClass, pHeroCreationMenu,_isPlaying);
	}


	setPointerNullDeleteObject(pHeroCreationMenu);
	setPointerNullDeleteObject(pHeroClass);
	setPointerNullDeleteObject(pMusicIsPlaying);
	setPointerNullDeleteObject(pMusicThread);
	setPointerNullDeleteObject(pArtwork);
	setPointerNullDeleteObject(pCommands);
	//setPointerNullDeleteObject(pStringifierClass);
	setPointerNullDeleteObject(pMainMenu);
#pragma endregion startMainLoop

	return 0;
}


#pragma region Deckweiﬂ
// int* pX = &X -> integer pointer names pX is set to the adress of X
// int y = *pX -> integer y is set to the thing pointed to by pX
// 
// int* pNumber -> Pointer to an integeradress
// &iNumber -> Adress of iNumber
// *pNumber -> Value of the adress of pNumber
// int* pNumber = &iNumber -> Pointer to the adress of iNumber
// int* pNumber = new int; -> Pointer to a new integeradress
// delete pNumber; -> free the adress of pNumber
// pNumber = nullptr; -> free the adress of pNumber
#pragma endregion Deckweiﬂ