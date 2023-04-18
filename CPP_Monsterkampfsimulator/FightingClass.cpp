#include "FightingClass.h"

void FightingClass::InitFight(Commands* const pCommands,HeroClass* pHeroClass)
{
	int currentHealth = pHeroClass->ModifyHealth();
	int maximumHealth = pHeroClass->ModifyHealth();
	int attack = pHeroClass->ModifyAttack();
	int defense = pHeroClass->ModifyDefense();
	int speed = pHeroClass->ModifySpeed();
	while (currentHealth >= 0)
	{
		int _rndNumber = 1; //for testing
		while (currentHealth >= 0)
		{
			m_Enemy = SelectEnemy(_rndNumber, m_factory, m_Enemy);
			StartFight(m_Enemy);
		}
	}
	HeroLost(pCommands);
}

Monster* FightingClass::SelectEnemy(int _rndNumber,std::shared_ptr<MonsterFactory> pMonsterFactory, Monster* m_Enemy)
{
	if (_rndNumber == 1) {
		MonsterFactory* pMonsterFactory = new FactoryDragon();
		m_Enemy = pMonsterFactory->createMonster();
	}
	if (_rndNumber == 2) {
		MonsterFactory* pMonsterFactory = new FactoryGoblin();
		m_Enemy = pMonsterFactory->createMonster();
	}
	if (_rndNumber == 3) {
		MonsterFactory* pMonsterFactory = new FactoryOgre();
		m_Enemy = pMonsterFactory->createMonster();
	}
	if (_rndNumber == 4) {
		MonsterFactory* pMonsterFactory = new FactoryOrc();
		m_Enemy = pMonsterFactory->createMonster();
	}
	if (_rndNumber == 5) {
		MonsterFactory* pMonsterFactory = new FactorySkeleton();
		m_Enemy = pMonsterFactory->createMonster();
	}
	if (_rndNumber == 6) {
		MonsterFactory* pMonsterFactory = new FactoryTroll();
		m_Enemy = pMonsterFactory->createMonster();
	}
	if (_rndNumber == 7) {
		MonsterFactory* pMonsterFactory = new FactoryVampire();
		m_Enemy = pMonsterFactory->createMonster();
	}
	if (_rndNumber == 8) {
		MonsterFactory* pMonsterFactory = new FactoryZombie();
		m_Enemy = pMonsterFactory->createMonster();
	}

	return m_Enemy;
}

void FightingClass::StartFight(Monster* m_Enemy)
{
	std::cout << "Der Kampf beginnt!";
}

void FightingClass::HeroLost(Commands* const pCommands)
{
}
