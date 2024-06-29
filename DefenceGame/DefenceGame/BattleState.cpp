#include "BattleState.h"
#include "WaveManager.h"
#include "EntityManager.h"
#include "MapManager.h"
#include "Player.h"

BattleState::BattleState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}

void BattleState::update()
{
	GET_SINGLETON(WaveManager)->spawnEnemy();

	entityUpdate();

	if (isWaveEnd())
	{
		deleteEnemyBody();
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
	}
	if (keyController() == KEY::ESC)
	{
		if (GET_SINGLETON(WaveManager)->isSpawnEnd())
		{
			for (auto& enemy : GET_SINGLETON(EntityManager)->getEnemies())
			{
				GET_SINGLETON(EntityManager)->despawnEntity(enemy);
				GET_SINGLETON(Player)->modifyHP(-1);
			}
			GET_SINGLETON(WaveManager)->reductWave();
		}
	}
}

void BattleState::render()
{
	gotoxy(49, 0);
	cout << " 현재 웨이브 :  " << GET_SINGLETON(WaveManager)->getCurrentWave();
	gotoxy(50, 1);
	cout << "남은 적 수 : " << GET_SINGLETON(EntityManager)->getEnemies().size() << "   ";

	if (GET_SINGLETON(WaveManager)->isSpawnEnd())
	{
		gotoxy(48, 2);
		cout << "ESC키를 눌러 항복";
	}
}

void BattleState::entityUpdate()
{
	for (auto& entity : GET_SINGLETON(EntityManager)->getEntities())
	{
		if (entity == nullptr)
			continue;
		entity->update();
	}
	GET_SINGLETON(EntityManager)->deleteEntity();
}

void BattleState::deleteEnemyBody()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH - 1; x++)
		{
			Cell* cell = GET_SINGLETON(MapManager)->getCell(Vector2(x, y));
			if (cell->type == MAP_TYPE::ROAD)
			{
				cell->setRenderString("  ");
			}
		}
	}
}

bool BattleState::isWaveEnd()
{
	return GET_SINGLETON(EntityManager)->getEnemies().size() <= 0 && GET_SINGLETON(WaveManager)->isSpawnEnd();
}
