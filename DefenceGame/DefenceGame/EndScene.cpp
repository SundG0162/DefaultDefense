#include "EndScene.h"
#include <iostream>
#include "WaveManager.h"
#include "Player.h"

#include "Define.h"
#include <fcntl.h>
#include <io.h>
#include "SceneManager.h"
#include"Key.h"


using namespace std;

EndScene::EndScene() {}

EndScene::~EndScene() {}

void EndScene::init()
{
}

void EndScene::update()
{
}

void EndScene::render()
{
    gotoxy(30, 0);
    cout << endl;
    int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
    if (GET_SINGLETON(Player)->getHP() == 0)
    {
        wcout << L"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗" << endl;
        wcout << L"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝" << endl;
        wcout << L"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ " << endl;
        wcout << L"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  " << endl;
        wcout << L" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   " << endl;
        wcout << L"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   " << endl;
    }
    else
    {
        wcout << L"██████╗ ███████╗███████╗███████╗ █████╗ ████████╗" << endl;
        wcout << L"██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗╚══██╔══╝" << endl;
        wcout << L"██║  ██║█████╗  █████╗  █████╗  ███████║   ██║   " << endl;
        wcout << L"██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██╔══██║   ██║   " << endl;
        wcout << L"██████╔╝███████╗██║     ███████╗██║  ██║   ██║   " << endl;
        wcout << L"╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   " << endl;
    }
    int curmode = _setmode(_fileno(stdout), prevmode);

    gotoxy(50, 10);
    cout << "버틴 웨이브 : " << WaveManager::getInstance()->getCurrentWave() << endl;
    gotoxy(50, 11);
    cout << "남은 골드 : " << GET_SINGLETON(Player)->getGold() << endl;
    gotoxy(99, 27);
    cout << "ESC를 눌러 타이틀로.." << endl;
}