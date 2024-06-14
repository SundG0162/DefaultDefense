#include "InfoScene.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include "Define.h"
#include "SceneManager.h"
#include "console.h"
#include "Key.h"

using namespace std;

InfoScene::InfoScene() {}
InfoScene::~InfoScene() {}

void InfoScene::init()
{
    srand(time(NULL));
    setCursorVisible(false, 1);
    lockResize();
}

void InfoScene::update()
{
    COORD Resolution = getConsoleResolution();
    int x = Resolution.X / 3;
    int y = Resolution.Y / 2.5;
    int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

    gotoxy(x + 7, y - 10);
    wcout << endl;
    wcout << L"   ██████  ██       █████  ██    ██  ██████  ██    ██ ██ ██████  ███████" << endl;
    wcout << L"   ██   ██ ██      ██   ██  ██  ██  ██       ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L" > ██████  ██      ███████   ████   ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
    wcout << L"   ██      ██      ██   ██    ██    ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"   ██      ███████ ██   ██    ██     ██████   ██████  ██ ██████  ███████" << endl << endl;

    gotoxy(x + 7, y - 2);
    wcout << endl;
    wcout << L"   ███████ ███    ██ ███████ ███    ███ ██    ██  ██████  ██    ██ ██ ██████  ███████" << endl;
    wcout << L"   ██      ████   ██ ██      ████  ████  ██  ██  ██       ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"   █████   ██ ██  ██ █████   ██ ████ ██   ████   ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
    wcout << L"   ██      ██  ██ ██ ██      ██  ██  ██    ██    ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"   ███████ ██   ████ ███████ ██      ██    ██     ██████   ██████  ██ ██████  ███████" << endl;

    gotoxy(x + 7, y + 6);
    wcout << endl;
    wcout << L"   ██████   █████   ██████ ██   ██" << endl;
    wcout << L"   ██   ██ ██   ██ ██      ██  ██ " << endl;
    wcout << L"   ██████  ███████ ██      █████  " << endl;
    wcout << L"   ██   ██ ██   ██ ██      ██  ██ " << endl;
    wcout << L"   ██████  ██   ██  ██████ ██   ██" << endl;

    _setmode(_fileno(stdout), prevmode);
}

void InfoScene::render()
{
    COORD Resolution = getConsoleResolution();
    int x = Resolution.X / 3;
    int y = Resolution.Y / 5.5;
    int originy = y;

    while (true)
    {
        KEY eKey = KeyController();
        switch (eKey)
        {
        case KEY::UP:
            if (y > originy)
            {
                gotoxy(x - 39, y);
                cout << " ";
                gotoxy(x - 39, y - 8);
                cout << ">";
                Sleep(100);
            }
            break;

        case KEY::DOWN:
            if (y < originy + 8)
            {
                gotoxy(x - 39, y);
                cout << " ";
                gotoxy(x - 39, y + 8);
                cout << ">";
                Sleep(100);
            }
            break;

        case KEY::SPACE:
            if (originy == y)
            {
                system("cls");
                COORD Resolution = getConsoleResolution();
                int x = Resolution.X / 4;
                int y = Resolution.Y / 4;
                int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

                gotoxy(x, y);
                wcout << endl;
                wcout << L"   ██████  ██       █████  ██    ██  ██████  ██    ██ ██ ██████  ███████" << endl;
                wcout << L"   ██   ██ ██      ██   ██  ██  ██  ██       ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L" > ██████  ██      ███████   ████   ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
                wcout << L"   ██      ██      ██   ██    ██    ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L"   ██      ███████ ██   ██    ██     ██████   ██████  ██ ██████  ███████" << endl;

                _setmode(_fileno(stdout), prevmode);

                gotoxy(x, y + 10);
                cout << endl;
                cout << "길을 따라오는 적들을 처치해 돈을 벌고, 병사들을 강화시키며 끝까지 버티는 게임입니다" << endl;
                cout << "총 50개의 웨이브가 있으며 웨이브마다 이전 라운드의 적의 숫자에서 5명씩 적이 추가됩니다" << endl;
                cout << "웨이브를 클리어한 후 10초간의 정비시간이 주어집니다" << endl;
                cout << "거점에 총 3마리의 적이 침입한다면 패배합니다" << endl << endl;

                cout << "조작" << endl;
                cout << "화살표 - 이동" << endl;
                cout << "스페이스바 - 선택" << endl;
                cout << "esc - 뒤로가기" << endl;
            }
            else if (originy + 8 == y)
            {
                system("cls");
                COORD Resolution = getConsoleResolution();
                int x = Resolution.X / 4;
                int y = Resolution.Y / 4;
                int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

                gotoxy(x, y);
                wcout << endl;
                wcout << L"   ███████ ███    ██ ███████ ███    ███ ██    ██  ██████  ██    ██ ██ ██████  ███████" << endl;
                wcout << L"   ██      ████   ██ ██      ████  ████  ██  ██  ██       ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L"   █████   ██ ██  ██ █████   ██ ████ ██   ████   ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
                wcout << L"   ██      ██  ██ ██ ██      ██  ██  ██    ██    ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L"   ███████ ██   ████ ███████ ██      ██    ██     ██████   ██████  ██ ██████  ███████" << endl;

                _setmode(_fileno(stdout), prevmode);

                gotoxy(x, y + 10);
                cout << endl;
                cout << "지금까지 발견한 적들의 정보를 확인할 수 있습니다" << endl << endl;
                cout << "???" << endl;
                cout << "???" << endl;
                cout << "???" << endl;
                cout << "???" << endl;
                cout << "???" << endl;
            }
            else if (originy + 16 == y)
            {
                GET_SINGLETON(SceneManager)->setTransition("TitleScene");
                GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
            }
            break;
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
    return KEY::FAIL;
}
