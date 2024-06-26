#include "FireWizard.h"

FireWizard::FireWizard(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
}

FireWizard::~FireWizard()
{
}

vector<Enemy*> FireWizard::defineTargets()
{
	return vector<Enemy*>();
}
