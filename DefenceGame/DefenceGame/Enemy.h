#pragma once
#include"Entity.h"
class Enemy : public Entity
{
public:
	Enemy(ENTITY_TYPE type, string renderString, const Vector2& spawnPos);
	virtual ~Enemy();
protected:
	int _hp;
	int _rewardGold;
	int _moveSpeed;
	Vector2 _facingDir;
public:
	virtual void Move();
	virtual void ModifyHP(int value);
	virtual bool CheckDead();
	virtual void Dead();
};

