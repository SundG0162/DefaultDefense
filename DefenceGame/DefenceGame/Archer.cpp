#include "Archer.h"

Archer::Archer(int attackTime, int attackRange, int damage, int price)
{
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
}

Archer::~Archer()
{
}

void Archer::attack()
{
}

Enemy* Archer::defineTarget()
{
	return nullptr;
}
