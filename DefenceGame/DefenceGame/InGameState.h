#pragma once
#include"InGameScene.h"
class InGameState
{
public:
	virtual ~InGameState() {}
	virtual void update() abstract;
	virtual void render() abstract;
protected:
	virtual KEY keyController();
protected:
	InGameScene* _inGameScene;
};