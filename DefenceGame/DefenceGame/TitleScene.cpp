#include "TitleScene.h"
#include "Define.h"
#include <iostream>
#include <Windows.h>
#include "console.h"
#include <fcntl.h>
#include <io.h>
#include "SceneManager.h"
#include "Key.h"
#include<conio.h>
#include "mci.h"

using namespace std;

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {}

void TitleScene::init() 
{
    srand(time(NULL));
    system("title !!!!DefaultDefence!!!!");
    setCursorVisible(false, 1);
    lockResize();
}

void TitleScene::update()
{
    int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"██████╗ ███████╗███████╗ █████╗ ██╗   ██╗██╗  ████████╗    ██████╗ ███████╗███████╗███████╗███╗   ██╗███████╗███████╗" << endl;
    wcout << L"██╔══██╗██╔════╝██╔════╝██╔══██╗██║   ██║██║  ╚══██╔══╝    ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝" << endl;
    wcout << L"██║  ██║█████╗  █████╗  ███████║██║   ██║██║     ██║       ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║███████╗█████╗  " << endl;
    wcout << L"██║  ██║██╔══╝  ██╔══╝  ██╔══██║██║   ██║██║     ██║       ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║╚════██║██╔══╝  " << endl;
    wcout << L"██████╔╝███████╗██║     ██║  ██║╚██████╔╝███████╗██║       ██████╔╝███████╗██║     ███████╗██║ ╚████║███████║███████╗" << endl;
    wcout << L"╚═════╝ ╚══════╝╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝       ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝" << endl;
    int curmode = _setmode(_fileno(stdout), prevmode);
}

void TitleScene::render()
{
    COORD Resolution = getConsoleResolution();
    int x = Resolution.X / 2.5;
    int y = Resolution.Y / 2.5;
    int originy = y;

    gotoxy(x - 2, y);
    cout << "> 게임 시작";
    gotoxy(x, y + 1);
    cout << "게임 정보";
    gotoxy(x, y + 2);
    cout << "게임 종료";

    gotoxy(x, y + 10);
    cout << "  사과?";

    while (true)
    {
        KEY eKey = KeyController();
        switch (eKey)
        {
        case KEY::UP:
            if (y > originy)
            {
                if (y == originy + 10)
                {
                    gotoxy(x - 2, y);
                    cout << " ";
                    gotoxy(x - 2, y -= 8);
                    cout << ">";
                }
                else
                {
                    gotoxy(x - 2, y);
                    cout << " ";
                    gotoxy(x - 2, --y);
                    cout << ">";
                    Sleep(100);
                }
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
            else if (y == originy + 2)
            {
                gotoxy(x - 2, y);
                cout << " ";
                gotoxy(x - 2, y+=8);
                cout << ">";
            }
            break;
        case KEY::ENTER:
        case KEY::SPACE:
            if (originy == y)
            {
                GET_SINGLETON(SceneManager)->setTransition("InGameScene");
                GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
            }
            if (originy + 1== y)
            {
                GET_SINGLETON(SceneManager)->setTransition("InfoScene");
                GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
            }
            if (originy + 2 == y)
            {
                exit(0);
            }
            if (y == originy + 10)
            {
                GET_SINGLETON(SceneManager)->loadScene("BadAppleScene");
            }
            system("cls");
            return;
        }
    }
}

KEY TitleScene::KeyController()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 0 || key == 224)
        {
            key = _getch();
            KEY eKey = (KEY)key;
            if (eKey == KEY::SPACE || eKey == KEY::ENTER)
            {
                PlayEffect(TEXT("Sounds\\UISelect.mp3"));
            }
            return eKey;
        }
        return (KEY)key;
    }
    return KEY::FAIL;
}
