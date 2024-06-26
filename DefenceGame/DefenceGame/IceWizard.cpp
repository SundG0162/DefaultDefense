#include "IceWizard.h"

IceWizard::IceWizard(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
}

IceWizard::~IceWizard()
{
}

vector<Enemy*> IceWizard::defineTargets()
{
	return vector<Enemy*>();
}
