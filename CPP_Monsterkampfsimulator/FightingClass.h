#pragma once
#include "MonsterFactory.h"
#include "HeroClass.h"
#include "MainMenu.h"
class FightingClass
{
public:
	void InitFight(Commands* const pCommands,HeroClass* pHeroClass, MonsterFactory* pMonsterFactory);
	Monster* SelectEnemy(int _rndNumber, MonsterFactory* pMonsterFactory, Monster* m_Enemy);
	void StartFight(Monster* m_Enemy);
	void HeroLost(Commands* const pCommands);
private:
	Monster* m_Enemy = nullptr;
protected:

};

