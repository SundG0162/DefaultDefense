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
private:
    int _tempPage = 0;
    int _currentPage = 0;
    int _currentGuidePage = 0;
};

