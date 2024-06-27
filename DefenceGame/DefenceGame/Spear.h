#pragma once
#include"Ally.h"
class Spear : public Ally
{
public:
	Spear(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price);
	~Spear();
public:
	vector<Enemy*> defineTargets() override;
};

