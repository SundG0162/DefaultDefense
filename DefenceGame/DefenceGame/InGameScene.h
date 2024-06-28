#pragma once
#include "Scene.h"
#include "Vector2.h"
#include "Key.h"
#include "Type.h"
#include<map>
class InGameState;
class InGameScene : public Scene
{
public:
	InGameScene();
	~InGameScene();
public:
	void init() override;
	void update() override;
	void render() override;
public:
	void changeState(INGAMESCENE_STATE state);
	void mapRender();
	void uiRender();
	void entityRender(const Vector2& pos);
private:
	InGameState* _currentState;
	std::map<INGAMESCENE_STATE, InGameState*> _stateMap;
};