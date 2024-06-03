#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
public:
	void init() override;
	void update() override;
	void render() override;
};

