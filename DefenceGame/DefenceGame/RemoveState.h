#pragma once
#include "InGameState.h"
#include"InGameScene.h"
class RemoveState : public InGameState
{
public:
	RemoveState(InGameScene* inGameScene);
public:
	void update() override;
	void render() override;
private:
	bool isInMap(const Vector2& pos);
	bool isCellEmpty();
private:
	Vector2 _currentMousePos;
};

