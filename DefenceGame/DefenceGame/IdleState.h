#pragma once
#include "InGameState.h"
#include"InGameScene.h"
class IdleState : public InGameState
{
public:
	IdleState(InGameScene* inGameScene);
public:
	void update() override;
	void render() override;
};

