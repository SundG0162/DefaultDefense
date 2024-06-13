#pragma once
#include"Cell.h"
#include"Define.h"

class MapManager
{
	DECLARE_SINGLETON(MapManager)
public:
	void setCell(const Cell& cell, int x, int y);
	Cell* getCell(int x, int y);
	void registerEntityInCell(Entity* entity, int x, int y);
	void deregisterEntityInCell(Entity* entity, int x, int y);
public:
	Cell arrMap[MAP_HEIGHT][MAP_WIDTH];
};