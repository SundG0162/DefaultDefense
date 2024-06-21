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
	template<typename T>
	vector<T*> getEntities(ENTITY_TYPE type);
	vector<Entity*> getEntities() { return entityVec; }
};

template<typename T>
std::vector<T*> Cell::getEntities(ENTITY_TYPE type) {
	std::vector<T*> entities;
	for (Entity* i : entityVec) {
		if (type == i->getType()) {
			T* specificEntity = dynamic_cast<T*>(i);
			entities.push_back(specificEntity);

		}
	}
	return entities;
}