#pragma once
#include "Ally.h"
#include"Enemy.h"
class Archer : public Ally
{
public:
	Archer();
	~Archer();
public:
	void attack() override;
	Enemy* defineTarget() override;
};