#include "Cell.h"
#include<algorithm>

Cell::Cell()
{
	bgColor = COLOR::BLACK;
	renderString = "  ";
}

void Cell::registerEntity(Entity* entity)
{
	entityVec.push_back(entity);
}

void Cell::deregisterEntity(Entity* entity)
{
	entityVec.erase(find(entityVec.begin(), entityVec.end(), entity));
}

void Cell::setRenderString(const string& str)
{
	renderString = str;
}

void Cell::setBGColor(COLOR color)
{
	bgColor = color;
}

vector<Entity*> Cell::getEntities(ENTITY_TYPE type)
{
	vector<Entity*> entities;
	for (Entity* entity : entityVec)
	{
		if (type == entity->getType())
			entities.push_back(entity);
	}
	return entities;
}