#pragma once
#include"Entity.h"
#include"Define.h"
class Enemy : public Entity
{
public:
	Enemy();
	virtual ~Enemy();
protected:
	int _hp;
	int _rewardGold;
	int _moveTime = 1000;
	int _lastMoveTime = 0;
	Vector2 _facingDir = Vector2(1,0);
	bool _isMoved = true;
	clock_t _moveTimer;
public:
	virtual void TryMove();
	virtual void Move();
	virtual void ModifyHP(int value);
	virtual bool CheckDead();
	virtual void Dead();
};

