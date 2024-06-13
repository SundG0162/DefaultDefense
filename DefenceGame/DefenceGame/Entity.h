#pragma once
#include "Vector2.h"
#include"Define.h"
#include <string>
enum class ENTITY_TYPE
{
	ALLY,
	ENEMY,
	TRAP
};

class Entity
{
protected:
	ENTITY_TYPE _type;
	Vector2 _currentPos;
	string _renderString;
public:
	ENTITY_TYPE getType() { return _type; }
	Vector2 getPos() { return _currentPos; }
	string getRenderString() { return _renderString; }
};

