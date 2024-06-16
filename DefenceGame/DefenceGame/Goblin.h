#pragma once
#include"Enemy.h"
class Goblin : public Enemy
{
public:
	Goblin(ENTITY_TYPE type, std::string renderString, COLOR color, int hp, int moveTime, int rewardGold);
};

