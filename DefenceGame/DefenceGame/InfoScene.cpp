#include "InfoScene.h"
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <Windows.h>
#include "Define.h"
#include "SceneManager.h"
#include "console.h"
#include "Key.h"
#include "TitleScene.h"

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
    wcout << L"   ██████  ██       █████  ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
    wcout << L"   ██   ██ ██      ██   ██  ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L" > ██████  ██      ███████   ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
    wcout << L"   ██      ██      ██   ██    ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"   ██      ███████ ██   ██    ██         ██████   ██████  ██ ██████  ███████" << endl << endl;

    gotoxy(x + 7, y - 2);
    wcout << endl;
    wcout << L"    █████  ██      ██      ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
    wcout << L"   ██   ██ ██      ██       ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"   ███████ ██      ██        ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
    wcout << L"   ██   ██ ██      ██         ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
    wcout << L"   ██   ██ ███████ ███████    ██         ██████   ██████  ██ ██████  ███████" << endl << endl;

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
                y -= 8;
                gotoxy(x - 39, y);
                cout << ">";
                Sleep(100);
            }
            break;

        case KEY::DOWN:
            if (y < originy + 16)
            {
                gotoxy(x - 39, y);
                cout << " ";
                y += 8;
                gotoxy(x - 39, y);
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

                gotoxy(x, y - 10);
                wcout << endl;
                wcout << L"     ██████  ██       █████  ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
                wcout << L"     ██   ██ ██      ██   ██  ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L"     ██████  ██      ███████   ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
                wcout << L"     ██      ██      ██   ██    ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L"     ██      ███████ ██   ██    ██         ██████   ██████  ██ ██████  ███████" << endl;

                _setmode(_fileno(stdout), prevmode);

                gotoxy(x, y);
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

                gotoxy(x, y - 10);
                wcout << endl;
                wcout << L"      █████  ██      ██      ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
                wcout << L"     ██   ██ ██      ██       ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L"     ███████ ██      ██        ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
                wcout << L"     ██   ██ ██      ██         ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
                wcout << L"     ██   ██ ███████ ███████    ██         ██████   ██████  ██ ██████  ███████" << endl << endl;

                _setmode(_fileno(stdout), prevmode);

                //1
                gotoxy(x, y + 1);
                cout << endl;
                cout << "궁수" << endl << "타겟 : 단일/선두 | 공속 : 1/s   | 공격력 : 5  | 가격 : 20골드   | 사거리 : 3칸" << endl;
                cout << "변방 왕국 출신의 궁수, 싼 값에 고용이 가능하지만 활을 그렇게 잘쏘는 편은 아니다.";
                gotoxy(x, y + 6);
                cout << endl;
                cout << "석궁병" << endl << "타겟 : 단일/선두 | 공속 : 0.1/s | 공격력 : 1  | 가격 : 50골드   | 사거리 : 5칸" << endl;
                cout << "석궁 조립에 온 신경을 쏟는지 연사 속도는 엄청나지만 각각의 위력은 약하다.";
                gotoxy(x, y + 11);
                cout << endl;
                cout << "발리스타" << endl << "타겟 : 단일/체력이 가장 높은 적 | 공속 : 10/s  | 공격력 : 200 | 가격 : 1000골드 | 사거리 : 10칸" << endl;
                cout << "한방 크게 터뜨리는 맛으로 사는 쾌락 주의자. 위력 만큼은 보장하지만...";
                gotoxy(x, y + 16);
                cout << endl;
                cout << "총잡이" << endl << "타겟 : 단일/체력이 가장 높은 적 | 공속 : 1/s   | 공격력 : 10  | 가격 : 100골드  | 사거리 : 5칸" << endl;
                cout << "서부 영화를 감명 깊게 봤는지 판초를 입고있다. 자세를 잡느라 장전이 조금 걸리는 편이다.";

                //2
                gotoxy(x, y + 1);
                cout << endl;
                cout << "화염마법사" << endl << "타겟 : 범위/선두 | 공속 : 3/s   | 공격력 : 10  | 가격 : 100골드  | 사거리 : 5칸  | 특징 : 지속데미지 " << endl;
                cout << "다혈질이라 그런지 불을 다룬다. 넓은 범위의 공격 때문에 아군도 가끔 피해를 입는다.";
                gotoxy(x, y + 6);
                cout << endl;
                cout << "얼음마법사" << endl << "타겟 : 범위/선두 | 공속 : 5/s   | 공격력 : 5   | 가격 : 500골드  | 사거리 : 5칸  | 특징 : 둔화" << endl;
                cout << "견습 얼음 마법사, 아직 위력이 약해 적을 얼리지는 못하고 느리게 만들 수는 있다.";
                gotoxy(x, y + 11);
                cout << endl;
                cout << "번개마법사" << endl << "타겟 : 범위/랜덤 | 공속 : 5/s   | 공격력 : 20  | 가격 : 500골드  | 사거리 : ∞" << endl;
                cout << "번개의 힘을 다루는 마법사. 번개가 어디로 튈지는 본인도 예상이 불가능하다.";

                //3
                gotoxy(x, y + 1);
                cout << endl;
                cout << "검병" << endl << "타겟 : 범위/선두 | 공속 : 0.5/s | 공격력 : 5  | 가격 : 20골드    | 사거리 : 1칸" << endl;
                cout << "기본에 충실한 기사. 끊임없는 연격이 특징이다.";
                gotoxy(x, y + 6);
                cout << endl;
                cout << "창병" << endl << "타겟 : 범위/선두 | 공속 : 0.1/s | 공격력 : 2  | 가격 : 50골드    | 사거리 : 1칸" << endl;
                cout << "무기로 긴 창을 선택한 이유는 낯을 가리기 때문이라고 한다.";
                gotoxy(x, y + 11);
                cout << endl;
                cout << "슬레이어" << endl << "타겟 : 단일/선두 | 공속 : 5/s   | 공격력 : 200 | 가격 : 1000골드 | 사거리 : 1칸" << endl;
                cout << "세검을 다루지만 괴이하게도 공격이 굉장히 느리다.";

            }
            else if (originy + 16 == y)
            {
                system("cls");
                GET_SINGLETON(SceneManager)->setTransition("TitleScene");
                GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
                return;
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
