#pragma once
#include"Ally.h"
class Sword : public Ally
{
public:
	Sword(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price);
	~Sword();
public:
	vector<Enemy*> defineTargets() override;
};

