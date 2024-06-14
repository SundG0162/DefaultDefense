#include "InfoScene.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include "Define.h"
#include "SceneManager.h"
#include "console.h"

using namespace std;

InfoScene::InfoScene() {}
InfoScene::~InfoScene(){}

void InfoScene::init()
{
    srand(time(NULL));
    setCursorVisible(false, 1);
    lockResize();
}

void InfoScene::update()
{
    int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
    int curmode = _setmode(_fileno(stdout), prevmode);
}

void InfoScene::render()
{
    COORD Resolution = getConsoleResolution();
    int x = Resolution.X / 3;
    int y = Resolution.Y / 2.5;
    int originy = y;

    gotoxy(x - 2, y);
    wcout << L"  ██████  ██       █████  ██    ██  ██████  ██    ██ ██ ██████  ███████" << endl;
    wcout << L"  ██   ██ ██      ██   ██  ██  ██  ██       ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"> ██████  ██      ███████   ████   ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
    wcout << L"  ██      ██      ██   ██    ██    ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"  ██      ███████ ██   ██    ██     ██████   ██████  ██ ██████  ███████" << endl;
    gotoxy(x, y + 5);
    wcout << L"███████ ███    ██ ███████ ███    ███ ██    ██  ██████  ██    ██ ██ ██████  ███████" << endl;
    wcout << L"██      ████   ██ ██      ████  ████  ██  ██  ██       ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"█████   ██ ██  ██ █████   ██ ████ ██   ████   ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
    wcout << L"██      ██  ██ ██ ██      ██  ██  ██    ██    ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"███████ ██   ████ ███████ ██      ██    ██     ██████   ██████  ██ ██████  ███████" << endl;
    gotoxy(x, y + 7);
    cout << "게임 종료";

    while (true)
    {
        KEY eKey = KeyController();
        switch (eKey)
        {
        case KEY::UP:
            if (y > originy)
            {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, --y);
                cout << ">";
                Sleep(100);
            }
            break;
        case KEY::DOWN:
            if (y < originy + 2)
            {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, ++y);
                cout << ">";
                Sleep(100);
            }
            break;
        case KEY::SPACE:
            if (originy == y)
            {
                GET_SINGLETON(SceneManager)->setTransition("InGameScene");
                GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
            }
            if (originy + 1 == y)
            {
                GET_SINGLETON(SceneManager)->setTransition("InfoScene");
                GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
            }
            if (originy + 2 == y)
            {

            }
            system("cls");
            return;
        }
    }
}

KEY InfoScene::KeyController()
{
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        return KEY::UP;
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        return KEY::DOWN;
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        return KEY::SPACE;
    }
}