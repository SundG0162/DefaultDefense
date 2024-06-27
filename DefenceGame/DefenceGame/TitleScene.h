#pragma once
#include "Scene.h"
#include "Key.h"

enum class MENU
{
	START, INFO, QUIT
};

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
public:
	void init() override;
	void update() override;
	void render() override;
	KEY KeyController();
};

