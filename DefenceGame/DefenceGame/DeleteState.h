#pragma once
#include "InGameState.h"
#include"InGameScene.h"
class DeleteState : public InGameState
{
public:
	DeleteState(InGameScene* inGameScene);
public:
	void update() override;
	void render() override;
};

