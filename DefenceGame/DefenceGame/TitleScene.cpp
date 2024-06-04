#include "TitleScene.h"
#include "Define.h"
#include <iostream>
#include <Windows.h>
#include "console.h"
#include <fcntl.h>
#include <io.h>

using namespace std;

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {}

void TitleScene::init() {}

void TitleScene::update()
{
    int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"██████╗ ███████╗███████╗ █████╗ ██╗   ██╗██╗  ████████╗    ██████╗ ███████╗███████╗███████╗███╗   ██╗ ██████╗███████╗" << endl;
    wcout << L"██╔══██╗██╔════╝██╔════╝██╔══██╗██║   ██║██║  ╚══██╔══╝    ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝" << endl;
    wcout << L"██║  ██║█████╗  █████╗  ███████║██║   ██║██║     ██║       ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║██║     █████╗  " << endl;
    wcout << L"██║  ██║██╔══╝  ██╔══╝  ██╔══██║██║   ██║██║     ██║       ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║██║     ██╔══╝  " << endl;
    wcout << L"██████╔╝███████╗██║     ██║  ██║╚██████╔╝███████╗██║       ██████╔╝███████╗██║     ███████╗██║ ╚████║╚██████╗███████╗" << endl;
    wcout << L"╚═════╝ ╚══════╝╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝       ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝ ╚═════╝╚══════╝" << endl;
    int curmode = _setmode(_fileno(stdout), prevmode);
}

void TitleScene::render()
{
    COORD Resolution = getConsoleResolution();
    int x = Resolution.X / 3;
    int y = Resolution.Y / 2.5;
    int originy = y;

    gotoxy(x - 2, y);
    cout << "> 게임 시작";
    gotoxy(x, y + 1);
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
            if (y < originy + 1)
            {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, ++y);
                cout << ">";
                Sleep(100);
            }
            break;
        case KEY::SPACE:
            system("cls");
            break;
        }
    }
}

KEY TitleScene::KeyController()
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