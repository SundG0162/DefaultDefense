#include "Enemy.h"
#include "Goblin.h"

Goblin::Goblin(ENTITY_TYPE type, std::string renderString, COLOR color, int hp, int moveTime, int rewardGold)
{
	type = type;
	_renderString = renderString;
	_color = color;
	_hp = hp;
	_moveTime = moveTime;
	_rewardGold = rewardGold;
}
