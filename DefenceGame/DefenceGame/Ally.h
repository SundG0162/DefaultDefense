#pragma once
#include "Entity.h"
class Ally : public Entity
{
public:
	Ally();
	virtual ~Ally();
private:
	int _attackTime = 500;
	int _damage = 5;
	int _price = 20;
public:
	virtual void attack() abstract;
	virtual Enemy* defineTarget() abstract;
};

