#pragma once
#include <iostream>
#include "MonsterFactory.h"
#include "Commands.h"
#include "HeroClass.h"
class FightingClass
{
public:
	void InitFight(Commands* const pCommands,HeroClass* pHeroClass);
	Monster* SelectEnemy(int _rndNumber, std::shared_ptr<MonsterFactory> pMonsterFactory, Monster* m_Enemy);
	void StartFight(Monster* m_Enemy);
	void HeroLost(Commands* const pCommands);
private:
	std::shared_ptr<MonsterFactory> m_factory = nullptr;
	Monster* m_Enemy = nullptr;
protected:

};

