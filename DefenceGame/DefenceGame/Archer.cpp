#include "Archer.h"

Archer::Archer(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
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
	Enemy* target = defineTarget();
}

Enemy* Archer::defineTarget()
{
	return nullptr;
}
