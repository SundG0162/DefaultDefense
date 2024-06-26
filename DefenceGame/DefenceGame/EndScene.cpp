#include "EndScene.h"
#include <iostream>
#include "WaveManager.h"
#include "Player.h"

using namespace std;

EndScene::EndScene() {}

EndScene::~EndScene() {}

void EndScene::render()
{
    cout << "버틴 웨이브 : " << WaveManager::getInstance()->getCurrentWave() << endl;
    cout << "남은 골드 : " << GET_SINGLETON(Player)->getGold() << endl;
}
