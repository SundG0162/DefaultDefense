#pragma once  
#include <fstream>
#include <Windows.h>
#include "console.h"
#include "Type.h"
#include "InGameState.h"
#include "InGameScene.h"
#include "Key.h"

class SelectState : public InGameState
{
public:
	SelectState(InGameScene* inGameScene);
public:
	void update() override;
	void render() override;
private:
	void spawnAlly();
private:
	int _currentPage = 1;
	int _currentSelectIndex = 1;
};
