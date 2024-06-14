#pragma once
#include "Entity.h"
#include "console.h"
#include "Define.h"
#include "Type.h"
class Cell
{
public:
	Cell();
	Cell(COLOR col, string str, MAP_TYPE type) : bgColor{ col }, renderString{ str }, _type{ type } {};
public:
	MAP_TYPE _type;
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