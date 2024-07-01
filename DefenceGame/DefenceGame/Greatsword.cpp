#include "Greatsword.h"
#include "Cell.h"
#include "MapManager.h"
#include "Direction.h"

Greatsword::Greatsword(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
	_lastAttackTime = -attackTime;

}

Greatsword::~Greatsword()
{
}

vector<Enemy*> Greatsword::defineTargets()
{
	vector<Enemy*> targetVec;
	for (int i = 0; i < 8; i++)
	{
		Vector2 pos = _currentPos + Direction::eightDirection[i];
		if (pos.x < 0 || pos.y < 0) continue;
		Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
		if (cell->type == MAP_TYPE::ROAD)
		{
			vector<Enemy*> vec = cell->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
			for (auto* enemy : vec)
			{
				targetVec.push_back(enemy);
			}
		}
	}
	return targetVec;
}
