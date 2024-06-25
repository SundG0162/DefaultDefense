#include "BattleState.h"
#include"WaveManager.h"
#include"EntityManager.h"


BattleState::BattleState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}

void BattleState::update()
{
	GET_SINGLETON(WaveManager)->spawnEnemy();

	if (GET_SINGLETON(WaveManager)->isSpawnEnd())
	{
		if (GET_SINGLETON(EntityManager)->getEnemies().size() <= 0)
		{
			_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
		}
	}
}

void BattleState::render()
{
}
