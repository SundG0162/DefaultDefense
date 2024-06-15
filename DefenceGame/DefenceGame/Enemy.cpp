#include "Enemy.h"
#include"MapManager.h"
#include"Define.h"
#include<time.h>
#include"EntityManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::tryMove()
{
	_moveTimer = clock();
	gotoxy(0, 0);
	cout << _currentPos.x << ", " << _currentPos.y;
	if (_moveTimer - _lastMoveTime > _moveTime)
	{
		move();
		_lastMoveTime = _moveTimer;
		_isMoved = true;
	}
}

void Enemy::move()
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(this, _currentPos);
	_currentPos += _facingDir;
	GET_SINGLETON(MapManager)->registerEntityInCell(this, _currentPos);
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
