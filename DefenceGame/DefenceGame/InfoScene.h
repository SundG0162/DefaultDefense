#pragma once
#include"Scene.h"
#include"Key.h"

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

