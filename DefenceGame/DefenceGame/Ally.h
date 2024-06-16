#pragma once
#include "Entity.h"
#include"Enemy.h"
class Ally : public Entity
{
public:
	Ally();
	virtual ~Ally();
protected:
	int _attackTime = 500;
	int _attackRange = 5;
	int _damage = 5;
	int _price = 20;
public:
	virtual void attack() abstract;
	virtual Enemy* defineTarget() abstract;
};

