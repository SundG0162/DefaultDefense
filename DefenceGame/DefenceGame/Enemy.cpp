#include "Enemy.h"
#include"MapManager.h"
#include"Define.h"
#include<time.h>
#include"EntityManager.h"
#include"Direction.h"

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
}

void Enemy::setRoad(ROAD_TYPE type)
{
	_roadType = type;
}

void Enemy::tryMove()
{
	_moveTimer = clock();
	if (_moveTimer - _lastMoveTime > _moveTime)
	{
		move();
		tryRotate();
		_lastMoveTime = _moveTimer;
	}
}

void Enemy::move()
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(this, _currentPos);
	_currentPos += _facingDir;
	GET_SINGLETON(MapManager)->registerEntityInCell(this, _currentPos);
}

void Enemy::tryRotate()
{
	if (!isOnRoad(_facingDir))
	{
		for (int i = 0; i < 4; i++)
		{
			Vector2 dir = Direction::fourDirection[i];
			if (_facingDir == dir || _facingDir * -1 == dir) 
				continue;
			if (isOnRoad(dir))
			{
				rotate(dir);
				break;
			}
		}
	}
}

bool Enemy::isOnRoad(Vector2 dir)
{
	return GET_SINGLETON(MapManager)->getCell(_currentPos + dir)->roadType == _roadType;
}

void Enemy::rotate(Vector2 dir)
{
	_facingDir = dir;
}

void Enemy::modifyHP(int value)
{
	_hp += value;
}

bool Enemy::checkDead()
{
	return _hp <= 0;
}

void Enemy::dead()
{
	GET_SINGLETON(EntityManager)->despawnEntity(this);
}

