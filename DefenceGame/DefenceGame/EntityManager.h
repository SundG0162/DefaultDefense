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
	void despawnAlly(Ally* ally);
	void despawnEnemy(Enemy* enemy);
	vector<Enemy*> getEnemies() { return _enemyVec; }
	vector<Ally*> getAllies() { return _allyVec; }
private:
	map<ALLY_TYPE, Ally*> _allyMap;
	map<ENEMY_TYPE, Enemy*> _enemyMap;
	vector<Enemy*> _enemyVec;
	vector<Ally*> _allyVec;
};

