#pragma once
#include "Ally.h"
#include"Enemy.h"
class Archer : public Ally
{
public:
	Archer(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price);
	~Archer();
public:
	void attack() override;
	Enemy* defineTarget() override;
};