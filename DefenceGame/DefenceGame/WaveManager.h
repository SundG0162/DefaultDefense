#pragma once
#include "Define.h"
#include "WaveInfo.h"
class WaveManager
{
	DECLARE_SINGLETON(WaveManager)
public:
	void init();
public:
	int getCurrentWave() { return _currentWave; }
	void initWave() { _currentWave = -1; }
	void nextWave();
	void spawnEnemy();
	bool isSpawnEnd() { return _currentSpawnEnemy == ENEMY_TYPE::END; }
	void reductWave() { _currentWave--; };
private:
	vector<WaveInfo> _waveInfoVec;
	ENEMY_TYPE _currentSpawnEnemy = ENEMY_TYPE::GOBLIN;
	ROAD_TYPE _spawnRoad = ROAD_TYPE::FIRST;
	int _leftSpawnEnemy = 0;
	int _currentWave = -1;
	int _spawnDelay = 800;
	clock_t _lastSpawnTime = 0;
	clock_t _spawnTimer = 0;
};

