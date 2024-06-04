#pragma once
#include "Scene.h"

enum class MENU
{
	START, QUIT
};
enum class KEY
{
	UP, DOWN, SPACE
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

