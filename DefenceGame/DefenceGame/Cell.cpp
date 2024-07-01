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
	else
	{
		static int y = 4;
		gotoxy(0, y++);
		cout << "적을 찾았음.";
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