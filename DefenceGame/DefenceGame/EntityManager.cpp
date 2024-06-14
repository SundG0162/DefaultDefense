#include "EntityManager.h"
#include "Archer.h"
#include"Goblin.h"
#include"Enemy.h"
#include"Define.h"
void EntityManager::init()
{
	_allyMap.insert({ ALLY_TYPE::DEFAULT, new Archer });

	_enemyMap.insert({ ENEMY_TYPE::DEFAULT, new Goblin(ENTITY_TYPE::ENEMY, string("G"), Vector2()) });
}

Ally* EntityManager::spawnAlly(ALLY_TYPE type, const Vector2& pos)
{
	Ally* ally = _allyMap[type];
	ally->setPos(pos);
	return ally;
}

Enemy* EntityManager::spawnEnemy(ENEMY_TYPE type, const Vector2& pos)
{
}

Entity* EntityManager::SpawnEntity(TRAP_TYPE type, const Vector2& pos)
{
}