#pragma once
#include"Enemy.h"
class Golem : public Enemy
{
public:
	Golem(ENTITY_TYPE type, std::string renderString, COLOR color, int hp, int moveTime, int rewardGold);
};

