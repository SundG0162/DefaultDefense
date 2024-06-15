#pragma once
#include "Vector2.h"
#include"Define.h"
#include "Type.h"
#include"console.h"
#include <string>

class Entity
{
public:
	Entity();
	virtual ~Entity();
protected:
	COLOR _color;
	ENTITY_TYPE type;
	Vector2 _currentPos;
	string _renderString;
public:
	COLOR getColor() { return _color; }
	ENTITY_TYPE getType() { return type; }
	Vector2 getPos() { return _currentPos; }
	string getRenderString() { return _renderString; }
	virtual void setPos(const Vector2& pos);
};