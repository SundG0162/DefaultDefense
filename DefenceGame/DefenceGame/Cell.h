#pragma once
#include "Entity.h"
#include "console.h"
#include "Define.h"
class Cell
{
public:
	Cell();
	Cell(COLOR col, string str) : bgColor{ col }, renderString{ str } {};
public:
	COLOR bgColor = COLOR::BLACK;
	string renderString = "  ";
	vector<Entity*> entityVec;
public:
	void registerEntity(Entity* entity);
	void deregisterEntity(Entity* entity);
	void setRenderString(const string& str);
	void setBGColor(COLOR color);
	vector<Entity*> getEntities(ENTITY_TYPE type);
};