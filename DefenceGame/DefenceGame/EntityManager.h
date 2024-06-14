#pragma once
#include "Define.h"
#include "Entity.h"
#include "Enemy.h"
#include "Type.h"
#include <map>
#include "Ally.h"
#include "Enemy.h"
#include "Vector2.h"
class EntityManager
{
	DECLARE_SINGLETON(EntityManager)
public:
	void init();
public:
	Ally* spawnAlly(ALLY_TYPE type, const Vector2& pos);
	Enemy* spawnEnemy(ENEMY_TYPE type, const Vector2& pos);
	Entity* SpawnEntity(TRAP_TYPE type, const Vector2& pos);
private:
	map<ALLY_TYPE, Ally*> _allyMap;
	map<ENEMY_TYPE, Enemy*> _enemyMap;
};

