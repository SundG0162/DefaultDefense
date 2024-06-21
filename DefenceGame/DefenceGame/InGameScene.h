#pragma once
#include"Scene.h"
#include"Vector2.h"
#include"Key.h"

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
	void enemyMove();
	void mapRender();
	void uiRender();
	void selectUIRender();
	void entityRender(const Vector2& pos);
	KEY KeyController();
};