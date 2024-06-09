#pragma once
#include "Scene.h"

class TransitionScene : public Scene
{
public:
    TransitionScene();
    ~TransitionScene();

    void init() override;
    void update() override;
    void render() override;
};
