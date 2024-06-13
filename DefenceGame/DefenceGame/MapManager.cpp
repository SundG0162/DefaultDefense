#include "MapManager.h"

MapManager* MapManager::m_pInst = nullptr;
void MapManager::setCell(const Cell& cell, int x, int y)
{
	arrMap[y][x] = cell;
}

Cell* MapManager::getCell(int x, int y)
{
	return &arrMap[y][x];
}

void MapManager::registerEntityInCell(Entity* entity, int x, int y)
{
	arrMap[x][y].registerEntity(entity);
}

void MapManager::deregisterEntityInCell(Entity* entity, int x, int y)
{
	arrMap[x][y].deregisterEntity(entity);
}