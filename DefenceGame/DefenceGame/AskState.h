#pragma once
#include "InGameState.h"
class AskState : public InGameState
{
public:
	AskState(InGameScene* inGameScene);
public:
	void update() override;
	void render() override;
};

