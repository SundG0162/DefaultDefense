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
	int _moveTime;
	int _lastMoveTime = 0;
	Vector2 _facingDir = Vector2(1,0);
	ROAD_TYPE _roadType;
	bool _isMoved = true;
	clock_t _moveTimer;
public:
	void setRoad(ROAD_TYPE type);
	void tryMove();
	void move();
	void modifyHP(int value);
	bool checkDead();
	void tryRotate();
	bool isOnRoad(Vector2 dir);
	void rotate(Vector2 dir);
	void dead();
};

