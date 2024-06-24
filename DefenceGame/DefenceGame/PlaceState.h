#pragma once
#include"InGameState.h"
#include"Vector2.h"
class PlaceState : public InGameState
{
public:
	PlaceState();
public:
	void update() override;
	void render() override;
private:
	Vector2 _currentMousePos;
};

