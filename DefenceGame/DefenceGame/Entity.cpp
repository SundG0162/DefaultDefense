#include "Entity.h"
#include"MapManager.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::setPos(const Vector2& pos)
{
	_currentPos = pos;
	GET_SINGLETON(MapManager)->registerEntityInCell(this, _currentPos);
}