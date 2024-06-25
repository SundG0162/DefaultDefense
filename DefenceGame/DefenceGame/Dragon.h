#pragma once
#include"Enemy.h"
class Dragon : public Enemy
{
public:
	Dragon(ENTITY_TYPE type, std::string renderString, COLOR color, int hp, int moveTime, int rewardGold);
};

