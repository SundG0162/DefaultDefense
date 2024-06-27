#include "LightningWizard.h"
#include"Cell.h"
#include"MapManager.h"
#include"EntityManager.h"
#include"Entity.h"
#include"Enemy.h"

LightningWizard::LightningWizard(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
}

LightningWizard::~LightningWizard()
{
}

vector<Enemy*> LightningWizard::defineTargets()
{
	vector<Enemy*> targetVec;
	vector<Enemy*> enemyVec = GET_SINGLETON(EntityManager)->getEnemies();
	if (enemyVec.size() == 0)
	{
		return targetVec;
	}
	int randIdx = rand() % enemyVec.size();
	targetVec = GET_SINGLETON(MapManager)->getCell(enemyVec[randIdx]->getPos())->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
	return targetVec;
}
