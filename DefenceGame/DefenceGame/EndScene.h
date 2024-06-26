#pragma once
#include "Scene.h"
#include "WaveManager.h"

class EndScene : public Scene
{
public:
    EndScene();
    ~EndScene();
public:
    void init() override;
    void update() override;
    void render() override;
};
