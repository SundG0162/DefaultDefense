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
#include "mci.h"
#include<conio.h>

using namespace std;

InfoScene::InfoScene() {}
InfoScene::~InfoScene() {}

void InfoScene::init()
{
	srand(time(NULL));
	setCursorVisible(false, 1);
	lockResize();

	_tempPage = 1;
	_currentPage = 0;
}

void InfoScene::update()
{
	KEY key = KeyController();


	switch (key)
	{
	case KEY::UP:
	{
		if (_tempPage > 1)
			_tempPage--;
		break;
	}
	case KEY::DOWN:
	{
		if (_tempPage < 3)
			_tempPage++;
		break;
	}
	case KEY::LEFT:
	{
		if (_currentGuidePage > 1)
		{
			system("cls");
			_currentGuidePage--;
		}
		break;
	}
	case KEY::RIGHT:
	{
		if (_currentGuidePage < 3)
		{
			system("cls");
			_currentGuidePage++;
		}
		break;
	}
	case KEY::SPACE:
	{
		system("cls");
		_currentPage = _tempPage;
		break;
	}
	case KEY::ENTER:
	{
		system("cls");
		_currentPage = _tempPage;
		break;
	}
	case KEY::ESC:
	{
		system("cls");
		if (_currentPage != 0)
		{
			_currentPage = 0;
		}
		else
		{
			GET_SINGLETON(SceneManager)->setTransition("TitleScene");
			GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
		}
		break;
	}
	}
}

void InfoScene::render()
{
	if (_currentPage == 0)
	{
		COORD Resolution = getConsoleResolution();
		int x = Resolution.X / 3;
		int y = Resolution.Y / 2.5;
		int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
		gotoxy(x + 7, y - 10);
		if (_tempPage == 1)
			setColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLACK);
		wcout << endl;
		wcout << L"   ██████  ██       █████  ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
		wcout << L"   ██   ██ ██      ██   ██  ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"   ██████  ██      ███████   ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
		wcout << L"   ██      ██      ██   ██    ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"   ██      ███████ ██   ██    ██         ██████   ██████  ██ ██████  ███████" << endl << endl;
		if (_tempPage == 1)
			setColor((int)COLOR::WHITE, (int)COLOR::BLACK);

		if (_tempPage == 2)
			setColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLACK);
		gotoxy(x + 7, y - 2);
		wcout << endl;
		wcout << L"    █████  ██      ██      ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
		wcout << L"   ██   ██ ██      ██       ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"   ███████ ██      ██        ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
		wcout << L"   ██   ██ ██      ██         ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"   ██   ██ ███████ ███████    ██         ██████   ██████  ██ ██████  ███████" << endl << endl;
		if (_tempPage == 2)
			setColor((int)COLOR::WHITE, (int)COLOR::BLACK);

		if (_tempPage == 3)
			setColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLACK);
		gotoxy(x + 7, y + 6);
		wcout << endl;
		wcout << L"   ██████   █████   ██████ ██   ██" << endl;
		wcout << L"   ██   ██ ██   ██ ██      ██  ██ " << endl;
		wcout << L"   ██████  ███████ ██      █████  " << endl;
		wcout << L"   ██   ██ ██   ██ ██      ██  ██ " << endl;
		wcout << L"   ██████  ██   ██  ██████ ██   ██" << endl;
		if (_tempPage == 3)
			setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		int curmode = _setmode(_fileno(stdout), prevmode);
	}
	else if (_currentPage == 1)
	{
		COORD Resolution = getConsoleResolution();
		int x = Resolution.X / 3;
		int y = Resolution.Y / 2.5;
		int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
		gotoxy(x, y - 10);
		wcout << endl;
		wcout << L"     ██████  ██       █████  ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
		wcout << L"     ██   ██ ██      ██   ██  ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"     ██████  ██      ███████   ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
		wcout << L"     ██      ██      ██   ██    ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"     ██      ███████ ██   ██    ██         ██████   ██████  ██ ██████  ███████" << endl;
		int curmode = _setmode(_fileno(stdout), prevmode);

		gotoxy(x, y);
		cout << endl;
		cout << "길을 따라오는 적들을 처치해 돈을 벌고, 더욱 강한 아군을 배치하여 끝까지 버티는 게임입니다" << endl;
		cout << "총 50개의 웨이브가 있으며 웨이브마다 적의 체력이 점점 늘어납니다." << endl;
		cout << "웨이브를 클리어한 정비시간이 주어집니다" << endl;
		cout << "거점에 총 3마리의 적이 침입한다면 패배합니다" << endl << endl;

		cout << "조작" << endl;
		cout << "화살표 - 이동" << endl;
		cout << "스페이스바, 엔터 - 선택" << endl;
		cout << "esc - 뒤로가기" << endl;
	}
	else if (_currentPage == 2)
	{
		COORD Resolution = getConsoleResolution();
		int x = Resolution.X / 3;
		int y = Resolution.Y / 2.5;
		int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
		gotoxy(x, y - 10);
		wcout << endl;
		wcout << L"      █████  ██      ██      ██    ██      ██████  ██    ██ ██ ██████  ███████" << endl;
		wcout << L"     ██   ██ ██      ██       ██  ██      ██       ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"     ███████ ██      ██        ████       ██   ███ ██    ██ ██ ██   ██ █████  " << endl;
		wcout << L"     ██   ██ ██      ██         ██        ██    ██ ██    ██ ██ ██   ██ ██     " << endl;
		wcout << L"     ██   ██ ███████ ███████    ██         ██████   ██████  ██ ██████  ███████" << endl << endl;
		int curmode = _setmode(_fileno(stdout), prevmode);

		cout << _currentGuidePage << " / 3";

		if (_currentGuidePage == 1)
		{
			gotoxy(x, y + 1);
			cout << endl;
			cout << "궁수" << endl << "타겟 : 단일/선두 | 공속 : 1/s   | 공격력 : 5  | 가격 : 20골드   | 사거리 : 3칸" << endl;
			cout << "변방 왕국 출신의 궁수, 싼 값에 고용이 가능하지만 활을 그렇게 잘쏘는 편은 아니다.";
			gotoxy(x, y + 5);
			cout << endl;
			cout << "석궁병" << endl << "타겟 : 단일/선두 | 공속 : 0.1/s | 공격력 : 1  | 가격 : 50골드   | 사거리 : 5칸" << endl;
			cout << "석궁 조립에 온 신경을 쏟는지 연사 속도는 엄청나지만 각각의 위력은 약하다.";
			gotoxy(x, y + 9);
			cout << endl;
			cout << "발리스타" << endl << "타겟 : 단일/체력이 가장 높은 적 | 공속 : 10/s | 공격력 : 200 | 가격 : 1000골드 | 사거리 : 10칸" << endl;
			cout << "한방 크게 터뜨리는 맛으로 사는 쾌락 주의자. 위력 만큼은 보장하지만...";
			gotoxy(x, y + 13);
			cout << endl;
			cout << "총잡이" << endl << "타겟 : 단일/체력이 가장 높은 적 | 공속 : 1/s  | 공격력 : 10  | 가격 : 100골드  | 사거리 : 5칸" << endl;
			cout << "서부 영화를 감명 깊게 봤는지 판초를 입고있다. 자세를 잡느라 장전이 조금 걸리는 편이다.";
		}
		else if (_currentGuidePage == 2)
		{
			gotoxy(x, y + 1);
			cout << endl;
			cout << "화염마법사" << endl << "타겟 : 범위/선두 | 공속 : 3/s   | 공격력 : 10  | 가격 : 400골드  | 사거리 : 5칸" << endl;
			cout << "다혈질이라 그런지 불을 다룬다. 넓은 범위의 공격 때문에 아군도 가끔 피해를 입는다.";
			gotoxy(x, y + 5);
			cout << endl;
			cout << "얼음마법사" << endl << "타겟 : 단일/선두 | 공속 : 5/s   | 공격력 : 5   | 가격 : 500골드  | 사거리 : 5칸  | 특징 : 둔화" << endl;
			cout << "견습 얼음 마법사, 아직 위력이 약해 적을 얼리지는 못하고 느리게 만들 수는 있다.";
			gotoxy(x, y + 9);
			cout << endl;
			cout << "번개마법사" << endl << "타겟 : 범위/랜덤 | 공속 : 5/s   | 공격력 : 20  | 가격 : 500골드  | 사거리 : ∞" << endl;
			cout << "번개의 힘을 다루는 마법사. 번개가 어디로 튈지는 본인도 예상이 불가능하다.";
			gotoxy(x, y + 13);
			cout << endl;
			cout << "네크로맨서" << endl;
			cout << "???" << endl;
			cout << "돌아오지 않는다. 그의 자리는 항상 공석이다.";
		}
		else if (_currentGuidePage == 3)
		{
			gotoxy(x, y + 1);
			cout << endl;
			cout << "검병" << endl << "타겟 : 범위/선두 | 공속 : 0.5/s | 공격력 : 5   | 가격 : 20골드    | 사거리 : 1칸" << endl;
			cout << "기본에 충실한 기사. 끊임없는 연격이 특징이다.";
			gotoxy(x, y + 5);
			cout << endl;
			cout << "창병" << endl << "타겟 : 범위/선두 | 공속 : 0.1/s | 공격력 : 2   | 가격 : 50골드    | 사거리 : 1칸" << endl;
			cout << "무기로 긴 창을 선택한 이유는 낯을 가리기 때문이라고 한다.";
			gotoxy(x, y + 9);
			cout << endl;
			cout << "슬레이어" << endl << "타겟 : 단일/선두 | 공속 : 3/s   | 공격력 : 200 | 가격 : 1000골드 | 사거리 : 1칸" << endl;
			cout << "세검을 다루지만 괴이하게도 공격이 굉장히 느리다.";
			gotoxy(x, y + 13);
			cout << endl;
			cout << "대검병" << endl << "타겟 : 주위 한칸 | 공속 : 4/s   | 공격력 : 300 | 가격 : 1500골드" << endl;
			cout << "자신의 몸보다 훨배는 커보이는 대검을 휘두르는 꼬마아이. 몸이 반동을 버티지 못해 휘두르면 한바퀴를 돌아버린다.";
		}

	}
	else if (_currentPage == 3)
	{
		system("cls");
		GET_SINGLETON(SceneManager)->setTransition("TitleScene");
		GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
		return;
	}
}

KEY InfoScene::KeyController()
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
