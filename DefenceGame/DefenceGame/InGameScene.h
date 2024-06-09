#pragma once
#include"Scene.h"
#include"Define.h"
class InGameScene : public Scene
{
public:
	InGameScene();
	~InGameScene();
private:
	void init() override;
	void update() override;
	void render() override;
private:
	char arrMap[MAP_HEIGHT][MAP_WIDTH];
};

