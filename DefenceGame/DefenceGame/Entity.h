#pragma once
#include "Vector2.h"
#include <string>
enum class ENTITY_TYPE
{
	ALLY,
	ENEMY,
	TRAP
};

class Entity
{
private:
	ENTITY_TYPE _type;
	Vector2 _currentPos;
public:
	ENTITY_TYPE getType() { return _type; }
	Vector2 getPos() { return _currentPos; }
};

