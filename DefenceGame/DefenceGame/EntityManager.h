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
	unique_ptr<Ally> spawnAlly(ALLY_TYPE type, const Vector2& pos);
	unique_ptr<Enemy> spawnEnemy(ENEMY_TYPE type, const Vector2& pos);
	void despawnAlly(Ally* ally);
	void despawnEnemy(Enemy* enemy);
	vector<unique_ptr<Enemy>> getEnemies() { return _enemyVec; }
	vector<unique_ptr<Ally>> getAllies() { return _allyVec; }
private:
	map<ALLY_TYPE, unique_ptr<Ally>> _allyMap;
	map<ENEMY_TYPE, unique_ptr<Enemy>> _enemyMap;
	vector<unique_ptr<Enemy>> _enemyVec;
	vector<unique_ptr<Ally>> _allyVec;
};

