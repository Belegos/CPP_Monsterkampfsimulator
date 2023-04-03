#pragma once
class HeroClass
{
public:
	int ModifyHealth();
	void ModifyHealth(const int& _newHealth);
	int GetAttack();
	void SetAttack(const int& _newAttack);
	int GetDefense();
	void SetDefense(const int& _newDefense);
	int GetSpeed();
	void SetSpeed(const int& _newSpeed);
private:
	int _heroHealth{};
	int _heroAttack{};
	int _heroDefense{};
	int _heroSpeed{};
};

