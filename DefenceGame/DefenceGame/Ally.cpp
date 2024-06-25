#include "Ally.h"

Ally::Ally()
{
}

Ally::~Ally()
{
}

void Ally::update()
{
	Entity::update();
	if (_timer - _lastAttackTime > _attackTime)
	{
		attack();
		_lastAttackTime = _timer;
	}
}

void Ally::attack()
{
	vector<Enemy*> targetVec = defineTargets();
	for (auto target : targetVec)
	{
		target->getDamage(_damage);
	}
}
