#pragma once
#include"Scene.h"
#include"Vector2.h"
#include"Key.h"
#include"InGameState.h"

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
	void entityUpdate();
	void mapRender();
	void uiRender();
	void selectUIRender();
	void entityRender(const Vector2& pos);
	KEY KeyController();
private:
	InGameState* _currentState;
	map<INGAMESCENE_STATE, InGameState*> _stateMap;
};