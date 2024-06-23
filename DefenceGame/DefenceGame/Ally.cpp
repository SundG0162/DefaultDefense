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
