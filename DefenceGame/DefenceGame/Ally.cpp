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
		_lastAttackTime = _timer;
		attack();
	}
}

void Ally::attack()
{
	vector<Enemy*> targetVec = defineTargets();
	if (targetVec.size() == 0)
	{
		_lastAttackTime = -_attackTime;
	}
	for (auto target : targetVec)
	{
		if (&target != nullptr)
			target->getDamage(_damage);
	}
}
