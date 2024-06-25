#include "WaveManager.h"
#include"Define.h"
#include"WaveInfo.h"
#include<fstream>
#include"EntityManager.h"

WaveManager* WaveManager::m_pInst = nullptr;

void WaveManager::init()
{
	std::fstream waveRead("WaveInfo\\WaveInfo.txt");
	if (waveRead.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			WaveInfo info = WaveInfo();
			for (int j = 0; j < 5; j++)
			{
				int read = waveRead.get() - '0';
				info.spawnEnemyMap.insert(std::make_pair((ENEMY_TYPE)(j + 1), read));
			}
			_waveInfoVec.push_back(info);
		}
	}
	waveRead.close();
}

void WaveManager::nextWave()
{
	_currentWave++;
	_leftSpawnEnemy = _waveInfoVec[_currentWave].spawnEnemyMap[_currentSpawnEnemy];
}

void WaveManager::spawnEnemy()
{
	if (_currentSpawnEnemy == ENEMY_TYPE::END) return;
	_spawnTimer = clock();
	if (_lastSpawnTime + _spawnDelay > _spawnTimer)
	{
		_lastSpawnTime = _spawnTimer;
		_leftSpawnEnemy--;
		GET_SINGLETON(EntityManager)->spawnEntity(_currentSpawnEnemy, ENEMY_SPAWNPOS, _spawnRoad);
		if (_leftSpawnEnemy <= 0)
		{
			_currentSpawnEnemy = (ENEMY_TYPE)((int)_currentSpawnEnemy + 1);
			if (_currentSpawnEnemy == ENEMY_TYPE::END) return;
			_leftSpawnEnemy = _waveInfoVec[_currentWave].spawnEnemyMap[_currentSpawnEnemy];
		}
	}
}
