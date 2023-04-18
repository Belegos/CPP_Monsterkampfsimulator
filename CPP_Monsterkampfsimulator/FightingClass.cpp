#include "FightingClass.h"

void FightingClass::InitFight(Commands* const pCommands, HeroClass* pHeroClass)
{

	while (pHeroClass->ModifyHealth() > 0)
	{
		int _rndNumber = 1; //for testing
		while (pHeroClass->ModifyHealth() > 0)
		{
			m_Enemy = SelectEnemy(_rndNumber, m_factory, m_Enemy);
			StartFight(m_Enemy, pHeroClass);
			if (pHeroClass->ModifyHealth() <= 0)break;
		}
		if (pHeroClass->ModifyHealth() <= 0)break;

	}
	HeroLost(pCommands, pHeroClass);
}

Monster* FightingClass::SelectEnemy(int _rndNumber, std::shared_ptr<MonsterFactory> pMonsterFactory, Monster* m_Enemy)
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

void FightingClass::StartFight(Monster* m_Enemy, HeroClass* pHeroClass)
{
	int _heroAttack = pHeroClass->ModifyAttack() - m_Enemy->ModifyDefense();
	int _enemyAttack = m_Enemy->ModifyAttack() - pHeroClass->ModifyDefense();

	std::cout << "Der Kampf beginnt!";

	while (pHeroClass->ModifyHealth() >= 1 || m_Enemy->ModifyHealth() >= 1)
		if (pHeroClass->ModifySpeed() > m_Enemy->ModifySpeed())
		{
			//hero attacks first
			HeroAttack(pHeroClass, _heroAttack, m_Enemy, _enemyAttack);
			if (m_Enemy->ModifyHealth() <= 0)break;
			EnemyAttack(pHeroClass, _heroAttack, m_Enemy, _enemyAttack);
			if (pHeroClass->ModifyHealth() <= 0)break;
		}
		else
		{
			//Enemy attacks first
			EnemyAttack(pHeroClass, _heroAttack, m_Enemy, _enemyAttack);
			if (pHeroClass->ModifyHealth() <= 0)break;
			HeroAttack(pHeroClass, _heroAttack, m_Enemy, _enemyAttack);
			if (m_Enemy->ModifyHealth() <= 0)break;
		}
}

void FightingClass::HeroLost(Commands* const pCommands, HeroClass* pHeroClass)
{
	std::cout << "Der Held hat noch: " << pHeroClass->ModifyHealth() << " Leben. Du hast verloren" << std::endl;
}

void FightingClass::HeroAttack(HeroClass* pHeroClass, int _heroAttack, Monster* m_Enemy, int _enemyAttack)
{
	if (pHeroClass->ModifyAttack() - m_Enemy->ModifyDefense() >= 1)
	{
		m_Enemy->ModifyHealth(m_Enemy->ModifyHealth() - _heroAttack);
		std::cout << "Hero hits Monster for " << _heroAttack << " damage." << std::endl;
		if (m_Enemy->ModifyHealth() < 0) { m_Enemy->ModifyHealth(0); }
		std::cout << "Monster has " << m_Enemy->ModifyHealth() << " left." << std::endl;
	}
	if (pHeroClass->ModifyAttack() - m_Enemy->ModifyDefense() < 1)
	{
		m_Enemy->ModifyHealth(m_Enemy->ModifyHealth()-1);
		std::cout << "Hero hits Monster for 1 damage." << std::endl;
		std::cout << "Monster has " << m_Enemy->ModifyHealth() << " left." << std::endl;
	}
}

void FightingClass::EnemyAttack(HeroClass* pHeroClass, int _heroAttack, Monster* m_Enemy, int _enemyAttack)
{
	if (m_Enemy->ModifyAttack() - pHeroClass->ModifyDefense() >= 1)
	{
		pHeroClass->ModifyHealth(pHeroClass->ModifyHealth()-_enemyAttack);
		std::cout << "Monster hits hero for " << _enemyAttack << " damage." << std::endl;
		if (pHeroClass->ModifyHealth() < 0) { pHeroClass->ModifyHealth(0); }
		std::cout << "Hero has " << pHeroClass->ModifyHealth() << " left." << std::endl;
	}
	if (m_Enemy->ModifyAttack() - pHeroClass->ModifyDefense() < 1)
	{
		pHeroClass->ModifyHealth(pHeroClass->ModifyHealth()-1);
		std::cout << "Monster hits Hero for 1 damage." << std::endl;
		std::cout << "Hero has " << pHeroClass->ModifyHealth() << " left." << std::endl;
	}
}
