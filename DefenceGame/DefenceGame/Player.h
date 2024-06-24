#pragma once
#include"Define.h"
#include"Ally.h"
#include"EntityManager.h"
class Player
{
	DECLARE_SINGLETON(Player)
private:
	Ally* _selectedAlly = GET_SINGLETON(EntityManager)->spawnEntity(ALLY_TYPE::ARCHER, Vector2());
public:
	void setAlly(Ally* ally) { _selectedAlly = ally; }
	Ally* getAlly() { return _selectedAlly; }
};