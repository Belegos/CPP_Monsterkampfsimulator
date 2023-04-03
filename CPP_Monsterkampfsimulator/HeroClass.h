#pragma once
class HeroClass
{
public:
	int ModifyHealth();
	int ModifyHealth(const int& _newHealth);
	int ModifyAttack();
	int ModifyAttack(const int& _newAttack);
	int ModifyDefense();
	int ModifyDefense(const int& _newDefense);
	int ModifySpeed();
	int ModifySpeed(const int& _newSpeed);
private:
	int _heroHealth;
	int _heroAttack;
	int _heroDefense;
	int _heroSpeed;
};

