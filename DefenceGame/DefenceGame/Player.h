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
};