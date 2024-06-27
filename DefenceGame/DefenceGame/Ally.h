#pragma once
#include "Entity.h"
#include "Enemy.h"
#include "Define.h"
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
	clock_t _lastAttackTime = 0;
public:
	int getPrice() { return _price; }
	int getAttackRange() { return _attackRange; }
	void update() override;
	virtual void attack();
	virtual vector<Enemy*> defineTargets() abstract;
};