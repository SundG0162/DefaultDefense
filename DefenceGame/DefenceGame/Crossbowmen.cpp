#include "Crossbowmen.h"
#include"Cell.h"
#include"MapManager.h"

Crossbowman::Crossbowman(ENTITY_TYPE type, std::string renderString, COLOR color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
}

Crossbowman::~Crossbowman()
{
}

vector<Enemy*> Crossbowman::defineTarget()
{
	vector<Enemy*> targetVec;
	int x = _currentPos.x - _attackRange / 2;
	int y = _currentPos.y - _attackRange / 2;
	int maxCount = 0;
	Vector2 attackCellPos = Vector2();
	for (int i = y; i < y + _attackRange; i++)
	{
		for (int j = x; j < x + _attackRange; j++)
		{
			Vector2 pos = Vector2(j, i);
			Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
			if (cell->type == MAP_TYPE::ROAD)
			{
				vector<Enemy*> vec = cell->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
				if (maxCount <= vec.front()->getMoveCount())
				{
					attackCellPos = pos;
				}
			}
		}
	}
	targetVec.push_back(GET_SINGLETON(MapManager)->
		getCell(attackCellPos)->
		getEntities<Enemy>(ENTITY_TYPE::ENEMY).front());
	return targetVec;
}
