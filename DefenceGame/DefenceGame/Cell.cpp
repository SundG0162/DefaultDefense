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
	renderString = entity->getRenderString();
	charColor = entity->getColor();
}

void Cell::deregisterEntity(Entity* entity)
{
	auto it = find(entityVec.begin(), entityVec.end(), entity);
	if (it != entityVec.end())
	{
		entityVec.erase(it);
		renderString = "  ";
		charColor = COLOR::WHITE;
		if (entityVec.size() != 0)
		{
			renderString = entityVec.back()->getRenderString();
			charColor = entityVec.back()->getColor();
		}
	}
}

void Cell::setRenderString(const string& str)
{
	renderString = str;
}

void Cell::setBGColor(COLOR color)
{
	bgColor = color;
}