#include "MapManager.h"
#include "Vector2.h"

MapManager* MapManager::m_pInst = nullptr;
void MapManager::setCell(const Cell& cell, const Vector2& pos)
{
	_arrMap[pos.y][pos.x] = cell;
}

Cell* MapManager::getCell(const Vector2& pos)
{
	return &_arrMap[pos.y][pos.x];
}

void MapManager::registerEntityInCell(Entity* entity, const Vector2& pos)
{
	_arrMap[pos.y][pos.x].registerEntity(entity);
}

void MapManager::deregisterEntityInCell(Entity* entity, const Vector2& pos)
{
	
	_arrMap[pos.y][pos.x].deregisterEntity(entity);
}