#pragma once
#include "Entity.h"
#include "console.h"
#include "Define.h"
#include "Type.h"
class Cell
{
public:
	Cell();
	Cell(COLOR col, string str, MAP_TYPE type, ROAD_TYPE roadType) : bgColor{ col }, renderString{ str }, type{ type }, roadType{ roadType } {};
public:
	MAP_TYPE type;
	ROAD_TYPE roadType;
	COLOR bgColor = COLOR::BLACK;
	COLOR charColor = COLOR::WHITE;
	string renderString = "  ";
	vector<Entity*> entityVec;
public:
	void registerEntity(Entity* entity);
	void deregisterEntity(Entity* entity);
	void setRenderString(const string& str);
	void setBGColor(COLOR color);
	vector<Entity*> getEntities(ENTITY_TYPE type);
	vector<Entity*> getEntities() { return entityVec; }
};