#pragma once
#include"InGameState.h"
class BattleState : public InGameState
{
public:
	BattleState(InGameScene* inGameScene);
public:
	void update() override;
	void render() override;
private:
	void entityUpdate();
	void deleteEnemyBody();
	bool isWaveEnd();
};

