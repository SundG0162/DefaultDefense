#pragma once
#include"InGameState.h"
#include"Vector2.h"
#include"InGameScene.h"
class PlaceState : public InGameState
{
public:
	PlaceState(InGameScene* inGameScene);
public:
	void update() override;
	void render() override;
private :
	bool isInMap(const Vector2& pos);
	bool isCellEmpty();
private:
	Vector2 _currentMousePos;
};

