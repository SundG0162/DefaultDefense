#pragma once
#include"Cell.h"
#include"Define.h"

class MapManager
{
	DECLARE_SINGLETON(MapManager)
public:
	void setCell(const Cell& cell, const Vector2& pos);
	Cell* getCell(const Vector2& pos);
	void registerEntityInCell(Entity* entity, const Vector2& pos);
	void deregisterEntityInCell(Entity* entity, const Vector2& pos);
public:
	Cell arrMap[MAP_HEIGHT][MAP_WIDTH];
};