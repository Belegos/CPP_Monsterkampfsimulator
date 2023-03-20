#pragma once

class Monster {
public:
	int monsterHealth{}; //braces initialize to zero
	Monster();
	~Monster();
private:
	void PrintMonster();
	void CreateMonster();
};;
