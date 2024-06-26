#pragma once
#include "Scene.h"
#include "WaveManager.h"

class EndScene : public Scene
{
public:
    EndScene();
    ~EndScene();
public:
    void render() override;
};
