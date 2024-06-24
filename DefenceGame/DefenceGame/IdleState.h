#pragma once
#include "InGameState.h"
class IdleState : public InGameState
{
public:
	IdleState();
public:
	void update() override;
	void render() override;
};

