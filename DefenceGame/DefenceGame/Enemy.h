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
	int _hitEffectTime = 200;
	int _moveCount = 0;
	bool _isHit = false;
	Vector2 _facingDir = Vector2(1,0);
	ROAD_TYPE _roadType;
	clock_t _moveTimer;
	clock_t _lastMoveTime = 0;
	clock_t _hitTimer;
	clock_t _lastHitTime = 0;
public:
	void update() override;
	void setRoad(ROAD_TYPE type);
	int getMoveCount() { return _moveCount; }
	int getHP() { return _hp; }
	void tryMove();
	void move();
	void getDamage(int value);
	void modifyHP(int value);
	bool checkDead();
	void tryRotate();
	bool isOnHouse();
	bool isOnRoad(Vector2 dir);
	void rotate(Vector2 dir);
	void dead();
};

