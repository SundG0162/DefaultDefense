#include "WaveManager.h"
#include "Define.h"
#include "WaveInfo.h"
#include<fstream>
#include "EntityManager.h"
#include "Define.h"
#include<sstream>

WaveManager* WaveManager::m_pInst = nullptr;

void WaveManager::init()
{
	std::fstream waveRead("WaveInfo\\WaveInfo.txt");
	if (waveRead.is_open())
	{
		for (int i = 0; i < 50; i++)
		{
			WaveInfo info = WaveInfo();
			string waveStr;
			std::getline(waveRead, waveStr);

			std::istringstream iss(waveStr);

			string buffer;
			vector<string> result;
			ENEMY_TYPE type = ENEMY_TYPE::GOBLIN;
			while (iss >> buffer)
			{
				info.spawnEnemyMap.insert(std::make_pair(type, std::stoi(buffer)));
				type = (ENEMY_TYPE)((int)type + 1);
			}
			_waveInfoVec.push_back(info);
		}
	}
	waveRead.close();
}

void WaveManager::nextWave()
{
	_currentWave++;
	_currentSpawnEnemy = ENEMY_TYPE::GOBLIN;
	_leftSpawnEnemy = _waveInfoVec[_currentWave].spawnEnemyMap[_currentSpawnEnemy];
}

void WaveManager::spawnEnemy()
{
	if (_currentSpawnEnemy == ENEMY_TYPE::END) return;
	_spawnTimer = clock();
	if (_lastSpawnTime + _spawnDelay < _spawnTimer)
	{
		_spawnRoad = _spawnRoad == ROAD_TYPE::FIRST ? ROAD_TYPE::SECOND : ROAD_TYPE::FIRST;
		_lastSpawnTime = _spawnTimer;
		_leftSpawnEnemy--;
		if (_leftSpawnEnemy >= 0)
			GET_SINGLETON(EntityManager)->spawnEntity(_currentSpawnEnemy, ENEMY_SPAWNPOS, _spawnRoad);
		if (_leftSpawnEnemy <= 0)
		{
			_currentSpawnEnemy = (ENEMY_TYPE)((int)_currentSpawnEnemy + 1);
			if (_currentSpawnEnemy == ENEMY_TYPE::END) return;
			_leftSpawnEnemy = _waveInfoVec[_currentWave].spawnEnemyMap[_currentSpawnEnemy];
		}
	}
}
