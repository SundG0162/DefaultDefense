#pragma once
#include"InGameScene.h"
class InGameState
{
public:
	virtual ~InGameState() {}
	virtual void update() abstract;
	virtual void render() abstract;
protected:
	InGameScene* _inGameScene;
};