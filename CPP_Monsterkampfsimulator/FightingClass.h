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
	void StartFight(Monster* m_Enemy,HeroClass* pHeroClass);
	void HeroLost(Commands* const pCommands, HeroClass* pHeroClass);
	void HeroAttack(HeroClass* pHeroClass, int _heroAttack,Monster* m_Enemy, int _enemyAttack);
	void EnemyAttack(HeroClass* pHeroClass, int _heroAttack,Monster* m_Enemy, int _enemyAttack);
private:
	std::shared_ptr<MonsterFactory> m_factory = nullptr;
	Monster* m_Enemy = nullptr;

	int currentHealth{};
	int maximumHealth{};
	int attack{};
	int defense{};
	int speed{};
protected:

};

