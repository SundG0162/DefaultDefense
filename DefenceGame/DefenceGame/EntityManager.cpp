#include "EntityManager.h"

#pragma region Enemy Includes
#include"Enemy.h"
#include"Goblin.h"
#include"GoldGoblin.h"
#include"Ogre.h"
#include"Golem.h"
#include"Dragon.h"
#pragma endregion

#pragma region Ally Includes
#include"Ally.h"
#include"Archer.h"
#include"Crossbow.h"
#include"Ballista.h"
#include"Define.h"
#pragma endregion

#include "MapManager.h"
EntityManager* EntityManager::m_pInst = nullptr;
void EntityManager::init()
{
	_allyMap.insert(std::make_pair(ALLY_TYPE::ARCHER, []() -> Ally* { return new Archer(ENTITY_TYPE::ALLY, "в║", COLOR::BLUE, 600, 10, 2, 20); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::CROSSBOW, []() -> Ally* { return new Crossbow(ENTITY_TYPE::ALLY, "в║", COLOR::BLUE, 600, 10, 2, 20); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::BALLISTA, []() -> Ally* { return new Ballista(ENTITY_TYPE::ALLY, "в║", COLOR::BLUE, 600, 10, 2, 20); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOBLIN, []() -> Enemy* { return new Goblin(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN, 10, 1000, 10); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOLDGOBLIN, []() -> Enemy* { return new GoldGoblin(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN, 10, 5000, 100); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::OGRE, []() -> Enemy* { return new Ogre(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN, 50, 500, 100); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOLEM, []() -> Enemy* { return new Golem(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN, 500, 100, 500); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::DRAGON, []() -> Enemy* { return new Dragon(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN, 1000, 1000, 1500); }));
}

Ally* EntityManager::spawnEntity(ALLY_TYPE type, const Vector2& pos)
{
	auto it = _allyMap.find(type);
	if (it != _allyMap.end())
	{
		Ally* ally = it->second();
		ally->setPos(pos);
		_allyVec.push_back(ally);
		_entityVec.push_back(ally);
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
		_entityVec.push_back(enemy);
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
		_entityVec.erase(find(_entityVec.begin(), _entityVec.end(), (Entity*)ally));
		_lazyDeleteVec.push_back(ally);
	}
}

void EntityManager::despawnEntity(Enemy* enemy)
{
	auto it = find(_enemyVec.begin(), _enemyVec.end(), enemy);

	if (it != _enemyVec.end())
	{
		GET_SINGLETON(MapManager)->deregisterEntityInCell(enemy, enemy->getPos());
		_enemyVec.erase(it);
		_entityVec.erase(find(_entityVec.begin(), _entityVec.end(), (Entity*)enemy));
		_lazyDeleteVec.push_back(enemy);
	}

}

void EntityManager::deleteEntity()
{
	for (auto& entity : _lazyDeleteVec)
	{
		auto it = find(_lazyDeleteVec.begin(), _lazyDeleteVec.end(), entity);
		_lazyDeleteVec.erase(it);
		delete entity;
	}
}
