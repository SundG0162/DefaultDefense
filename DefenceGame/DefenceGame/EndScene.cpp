#include "EndScene.h"
#include <iostream>
#include "WaveManager.h"

EndScene::EndScene() {}

EndScene::~EndScene() {}

void EndScene::render() {
    std::cout << "현재 웨이브: " << WaveManager::getInstance()->getCurrentWave() << std::endl;
}
