#pragma once
#include "Define.h"
#include "Type.h"
struct WaveInfo
{
	WaveInfo() : spawnDelay{ 0 } {};
	map<ENEMY_TYPE, int> spawnEnemyMap;
	int spawnDelay;
};

