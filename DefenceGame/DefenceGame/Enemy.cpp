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

void Enemy::TryMove()
{
	_moveTimer = clock();
	gotoxy(0, 0);
	cout << _currentPos.x << ", " << _currentPos.y;
	if (_moveTimer - _lastMoveTime > _moveTime)
	{
		Move();
		_lastMoveTime = _moveTimer;
		_isMoved = true;
	}
}

void Enemy::Move()
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(this, _currentPos);
	_currentPos += _facingDir;
	GET_SINGLETON(MapManager)->registerEntityInCell(this, _currentPos);
}

void Enemy::ModifyHP(int value)
{
	_hp += value;
}

bool Enemy::CheckDead()
{
	return _hp <= 0;
}

void Enemy::Dead()
{
	GET_SINGLETON(EntityManager)->despawnEntity(this);
}
