#pragma once
#include"Define.h"
#include"Ally.h"
#include"EntityManager.h"
class Player
{
	DECLARE_SINGLETON(Player)
private:
	Ally* _selectedAlly = nullptr;
public:
	void setAlly(Ally* ally) { _selectedAlly = ally; }
	Ally* getAlly() { return _selectedAlly; }
	void modifyHP(int value) { _hp += value; }
	void modifyGold(int value) { _gold += value; }
	int getGold() { return _gold; }
	int getHP() { return _hp; }
private:
	int _hp = 3;
	int _gold = 0;
};