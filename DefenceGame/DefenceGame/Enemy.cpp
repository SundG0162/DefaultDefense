#include "Enemy.h"
#include"MapManager.h"
#include"Define.h"


Enemy::Enemy(ENTITY_TYPE type, string renderString, const Vector2& spawnPos)
{
	_type = type;
	_renderString = renderString;
	_currentPos = spawnPos;
}

Enemy::~Enemy()
{
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
	GET_SINGLETON(MapManager)->deregisterEntityInCell(this, _currentPos);
}
