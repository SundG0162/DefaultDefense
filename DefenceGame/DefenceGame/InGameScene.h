#pragma once
#include"Scene.h"
class InGameScene : public Scene
{
public:
	InGameScene();
	~InGameScene();
private:
	void init() override;
	void update() override;
	void render() override;
};

