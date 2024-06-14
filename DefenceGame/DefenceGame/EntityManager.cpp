#include "EntityManager.h"
#include "Archer.h"
#include"Goblin.h"
#include"Enemy.h"
#include"Define.h"
#include "MapManager.h"
#include<map>
EntityManager* EntityManager::m_pInst = nullptr;
void EntityManager::init()
{
	_allyMap.insert({ ALLY_TYPE::ARCHER, std::make_unique<Archer>()});

	_enemyMap.insert({ ENEMY_TYPE::GOBLIN, std::make_unique<Goblin>(ENTITY_TYPE::ENEMY, "бс", COLOR::GREEN)});
}

unique_ptr<Ally> EntityManager::spawnAlly(ALLY_TYPE type, const Vector2& pos)
{
	auto it = _allyMap.find(type);
	if (it != _allyMap.end())
	{
		unique_ptr<Ally> ally = std::make_unique<Ally>(*(it->second));
		ally->setPos(pos);
		_allyVec.push_back(std::move(ally));
		return ally;
	}
	return nullptr;
}

unique_ptr<Enemy> EntityManager::spawnEnemy(ENEMY_TYPE type, const Vector2& pos)
{
	auto it = _enemyMap.find(type);
	if (it != _enemyMap.end())
	{

		unique_ptr<Enemy> enemy = std::make_unique<Enemy>(*(it->second));
		enemy->setPos(pos);
		_enemyVec.push_back(std::move(enemy));
		return enemy;
	}
	return nullptr;
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
