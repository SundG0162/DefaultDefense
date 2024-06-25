#pragma once
#include"Ally.h"
class Crossbowman : public Ally
{
public:
	Crossbowman(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price);
	~Crossbowman();
public:
	vector<Enemy*> defineTargets() override;
};

