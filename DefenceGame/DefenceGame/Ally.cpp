#include "Ally.h"

Ally::Ally()
{
}

Ally::~Ally()
{
}

void Ally::update()
{
	_attackTimer = clock();
	if (_attackTimer - _lastAttackTime > _attackTime)
	{
		attack();
		_lastAttackTime = _attackTimer;
	}
}
