#include "GoldGoblin.h"
#include "Enemy.h"

GoldGoblin::GoldGoblin(ENTITY_TYPE type, std::string renderString, COLOR color, int hp, int moveTime, int rewardGold)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_hp = hp;
	_moveTime = moveTime;
	_rewardGold = rewardGold;
	_originColor = _color;
}
