#include "Enemy.h"
#include "Goblin.h"

Goblin::Goblin(ENTITY_TYPE type, std::string renderString, COLOR color)
{
	type = type;
	_renderString = renderString;
	_color = color;
}
