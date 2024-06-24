#pragma once
#include"InGameState.h"
#include"Vector2.h"
#include"InGameScene.h"
class PlaceState : public InGameState
{
public:
	PlaceState(InGameScene* inGameScene) : _inGameScene{ inGameScene } {};
public:
	void update() override;
	void render() override;
private :
	bool isInMap(const Vector2& pos);
private:
	InGameScene* _inGameScene;
	Vector2 _currentMousePos;
};

