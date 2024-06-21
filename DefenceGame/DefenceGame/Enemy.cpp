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

void Enemy::update()
{
	_timer = clock();
	tryMove();
	if (_isHit)
	{
		if (_timer - _lastHitTime > _hitEffectTime)
		{
			_color = _originColor;
			GET_SINGLETON(MapManager)->getCell(_currentPos)->charColor = _color;
			_isHit = false;
		}
	}
}

void Enemy::tryMove()
{
	if (_timer - _lastMoveTime > _moveTime)
	{
		move();
		tryRotate();
		_lastMoveTime = _timer;
	}
}

void Enemy::move()
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(this, _currentPos);
	_currentPos += _facingDir;
	_moveCount++;
	GET_SINGLETON(MapManager)->registerEntityInCell(this, _currentPos);
}

void Enemy::getDamage(int value)
{
	_isHit = true;
	_lastHitTime = _timer;
	_color = COLOR::RED;
	GET_SINGLETON(MapManager)->getCell(_currentPos)->charColor = _color;
	modifyHP(-value);
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
	if (checkDead())
	{
		dead();
	}
}

bool Enemy::checkDead()
{
	return _hp <= 0;
}

void Enemy::dead()
{
	GET_SINGLETON(EntityManager)->despawnEntity(this);
}

