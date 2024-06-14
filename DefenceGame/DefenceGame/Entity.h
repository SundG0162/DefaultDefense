#pragma once
#include "Vector2.h"
#include"Define.h"
#include "Type.h"
#include <string>

class Entity
{
public:
	Entity();
	virtual ~Entity();
protected:
	ENTITY_TYPE _type;
	Vector2 _currentPos;
	string _renderString;
public:
	ENTITY_TYPE getType() { return _type; }
	Vector2 getPos() { return _currentPos; }
	string getRenderString() { return _renderString; }
	virtual void setPos(const Vector2& pos);
};

