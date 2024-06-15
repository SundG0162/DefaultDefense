#include "EntityManager.h"
#include "Archer.h"
#include"Goblin.h"
#include"Enemy.h"
#include"Define.h"
#include "MapManager.h"
EntityManager* EntityManager::m_pInst = nullptr;
void EntityManager::init()
{
	_allyMap.insert(std::make_pair(ALLY_TYPE::ARCHER, []() -> Ally* { return new Archer(); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOBLIN, []() -> Enemy* { return new Goblin(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN); }));
}

Ally* EntityManager::spawnEntity(ALLY_TYPE type, const Vector2& pos)
{
	auto it = _allyMap.find(type);
	if (it != _allyMap.end())
	{
		Ally* ally = it->second();
		ally->setPos(pos);
		_allyVec.push_back(ally);
		return ally;
	}
	return nullptr;
}

Enemy* EntityManager::spawnEntity(ENEMY_TYPE type, const Vector2& pos)
{
	auto it = _enemyMap.find(type);
	if (it != _enemyMap.end())
	{
		Enemy* enemy = it->second();
		enemy->setPos(pos);
		_enemyVec.push_back(enemy);
		return enemy;
	}
	return nullptr;
}


void EntityManager::despawnEntity(Ally* ally)
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(ally, ally->getPos());
	auto it = find(_allyVec.begin(), _allyVec.end(), ally);
	if (it != _allyVec.end())
	{
		_allyVec.erase(it);
		delete& it;
	}
}

void EntityManager::despawnEntity(Enemy* enemy)
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(enemy, enemy->getPos());
	auto it = find(_enemyVec.begin(), _enemyVec.end(), enemy);
	if (it != _enemyVec.end())
	{
		_enemyVec.erase(it);
		delete& it;
	}
}
