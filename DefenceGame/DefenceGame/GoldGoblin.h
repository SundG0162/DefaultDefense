#pragma once
#include"Enemy.h"
class GoldGoblin : public Enemy
{
public:
	GoldGoblin(ENTITY_TYPE type, std::string renderString, COLOR color, int hp, int moveTime, int rewardGold);
};

