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

void TitleScene::update() {
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

void EnterAnimation()
{
    COORD Resolution = getConsoleResolution();
    int width = Resolution.X;
    int height = Resolution.Y;
    int animtime = 50;

    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::RED);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::LIGHT_RED);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::YELLOW);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::GREEN);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::LIGHT_BLUE);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::BLUE);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::LIGHT_VIOLET);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::WHITE);
    system("cls");
    Sleep(animtime);

    animtime -= 30;

    setColor((int)COLOR::BLACK, (int)COLOR::WHITE);
    for (int i = 0; i < width / 2; ++i)
    {
        for (int j = 0; j < height; j += 2)
        {
            gotoxy(i * 2, j);
            cout << "  ";
        }
        for (int j = 1; j < height; j += 2)
        {
            gotoxy(width - 2 - i * 2, j);
            cout << "  ";
        }
        Sleep(animtime);
    }
    setColor((int)COLOR::WHITE);
    system("cls");
}