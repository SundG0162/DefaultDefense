#include "EntityManager.h"
#include "Archer.h"
#include"Goblin.h"
#include"Enemy.h"
#include"Define.h"
#include "MapManager.h"
EntityManager* EntityManager::m_pInst = nullptr;
void EntityManager::init()
{
	_allyMap.insert({ ALLY_TYPE::ARCHER, new Archer });

	_enemyMap.insert({ ENEMY_TYPE::GOBLIN, new Goblin(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN) });
}

Ally* EntityManager::spawnAlly(ALLY_TYPE type, const Vector2& pos)
{
	Ally* ally = _allyMap[type];
	ally->setPos(pos);
	_allyVec.push_back(ally);
	return ally;
}

Enemy* EntityManager::spawnEnemy(ENEMY_TYPE type, const Vector2& pos)
{
	Enemy* enemy = _enemyMap[type];
	enemy->setPos(pos);
	_enemyVec.push_back(enemy);
	return enemy;
}

void EntityManager::despawnAlly(Ally* ally)
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(ally, ally->getPos());
	auto it = find(_allyVec.begin(), _allyVec.end(), ally);
	if (it != _allyVec.end())
	{
		_allyVec.erase(it);
	}
}

void EntityManager::despawnEnemy(Enemy* enemy)
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(enemy, enemy->getPos());
	auto it = find(_enemyVec.begin(), _enemyVec.end(), enemy);
	if (it != _enemyVec.end())
	{
		_enemyVec.erase(it);
	}
}
