#pragma once
#include"Scene.h"

enum class KEY
{
    UP, DOWN, SPACE
};

class InfoScene : public Scene
{
public:
    InfoScene();
    ~InfoScene();
public:
    void init() override;
    void update() override;
    void render() override;
    KEY KeyController();
};

