#include "EntityManager.h"
#include "Archer.h"
#include"Goblin.h"
#include"Enemy.h"
#include"Define.h"
#include "MapManager.h"
EntityManager* EntityManager::m_pInst = nullptr;
void EntityManager::init()
{
	_allyMap.insert(std::make_pair(ALLY_TYPE::ARCHER, []() -> Ally* { return new Archer(ENTITY_TYPE::ALLY, "¢º", COLOR::BLUE, 600, 10, 2, 20); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOBLIN, []() -> Enemy* { return new Goblin(ENTITY_TYPE::ENEMY, "¡á", COLOR::GREEN, 10, 1000, 10); }));
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

Enemy* EntityManager::spawnEntity(ENEMY_TYPE type, const Vector2& pos, ROAD_TYPE road)
{
	auto it = _enemyMap.find(type);
	if (it != _enemyMap.end())
	{
		Enemy* enemy = it->second();
		Vector2 spawnPos = pos;
		spawnPos = road == ROAD_TYPE::FIRST ? spawnPos : spawnPos + Vector2(0, 1);
		enemy->setPos(spawnPos);
		enemy->setRoad(road);
		_enemyVec.push_back(enemy);
		return enemy;
	}
	return nullptr;
}


void EntityManager::despawnEntity(Ally* ally)
{
	auto it = find(_allyVec.begin(), _allyVec.end(), ally);
	if (it != _allyVec.end())
	{
		GET_SINGLETON(MapManager)->deregisterEntityInCell(ally, ally->getPos());
		_allyVec.erase(it);
		delete ally;
	}
	gotoxy(0, 1);
	cout << "»èÁ¦";
}

void EntityManager::despawnEntity(Enemy* enemy)
{
	auto it = find(_enemyVec.begin(), _enemyVec.end(), enemy);
	if (it != _enemyVec.end())
	{
		GET_SINGLETON(MapManager)->deregisterEntityInCell(enemy, enemy->getPos());
		_enemyVec.erase(it);
		delete enemy;
	}
}
