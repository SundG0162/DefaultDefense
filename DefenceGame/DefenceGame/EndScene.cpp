#include "EndScene.h"
#include <iostream>
#include "WaveManager.h"
#include "Player.h"
#include<conio.h>
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
    if (keyController() == KEY::ESC)
    {
        GET_SINGLETON(SceneManager)->setTransition("TitleScene");
        GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
    }
}

void EndScene::render()
{
    gotoxy(30, 0);
    int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
    int x = 33;
    int y = 1;
    if (GET_SINGLETON(Player)->getHP() > 0)
    {
        gotoxy(x, y++);
        wcout << L"██╗   ██╗██╗ ██████╗████████╗ ██████╗ ██████╗ ██╗   ██╗";
        gotoxy(x, y++);
        wcout << L"██║   ██║██║██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝";
        gotoxy(x, y++);
        wcout << L"██║   ██║██║██║        ██║   ██║   ██║██████╔╝ ╚████╔╝ ";
        gotoxy(x, y++);
        wcout << L"╚██╗ ██╔╝██║██║        ██║   ██║   ██║██╔══██╗  ╚██╔╝  ";
        gotoxy(x, y++);
        wcout << L" ╚████╔╝ ██║╚██████╗   ██║   ╚██████╔╝██║  ██║   ██║   ";
        gotoxy(x, y);
        wcout << L"  ╚═══╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ";
    }
    else
    {
        gotoxy(x, y++);
        wcout << L"██████╗ ███████╗███████╗███████╗ █████╗ ████████╗";
        gotoxy(x, y++);
        wcout << L"██╔══██╗██╔════╝██╔════╝██╔════╝██╔══██╗╚══██╔══╝";
        gotoxy(x, y++);
        wcout << L"██║  ██║█████╗  █████╗  █████╗  ███████║   ██║   ";
        gotoxy(x, y++);
        wcout << L"██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██╔══██║   ██║   ";
        gotoxy(x, y++);
        wcout << L"██████╔╝███████╗██║     ███████╗██║  ██║   ██║   ";
        gotoxy(x, y);
        wcout << L"╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ";
    }
    int curmode = _setmode(_fileno(stdout), prevmode);

    gotoxy(50, 10);
    cout << "버틴 웨이브 : " << WaveManager::getInstance()->getCurrentWave() - 1;
    gotoxy(50, 12);
    cout << "남은 골드 : " << GET_SINGLETON(Player)->getGold();
    gotoxy(50, 14);
    cout << "총 모은 골드 : " << GET_SINGLETON(Player)->getTotalGold();
    gotoxy(99, 27);
    cout << "ESC를 눌러 타이틀로.." << endl;
}

KEY EndScene::keyController()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 0 || key == 224)
        {
            key = _getch();
            return (KEY)key;
        }
        return (KEY)key;
    }
    return KEY::FAIL;
}
