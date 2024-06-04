#pragma once
#include "Scene.h"

class TransitionScene : public Scene
{
public:
    TransitionScene();
    ~TransitionScene();

    void render() override;
};
