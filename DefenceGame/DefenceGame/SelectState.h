#pragma once  
#include <fstream>
#include <Windows.h>
#include"console.h"
#include"Type.h"
#include"InGameState.h"
#include"Key.h"

void Render()
{
	int page = 0;

	while (true)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::RIGHT:
			if (page < 3)
				page++;
			break;
		case KEY::LEFT:
			if (page > 0)
				page--;
			break;
		}
	}

	if (page == 1)
	{
		gotoxy(92, 6);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 7);
		cout << "■◇궁수    | 사거리: 3칸 ■" << endl;
		gotoxy(92, 8);
		cout << "■가격: 20  | 공격력: 5   ■" << endl;
		gotoxy(92, 9);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 11);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 12);
		cout << "■◇석궁병  | 사거리: 5칸 ■" << endl;
		gotoxy(92, 13);
		cout << "■가격: 50  | 공격력: 1   ■" << endl;
		gotoxy(92, 14);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 16);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 17);
		cout << "■◇발리스타| 사거리: 10칸■" << endl;
		gotoxy(92, 18);
		cout << "■가격: 1000| 공격력: 200 ■" << endl;
		gotoxy(92, 19);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 21);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 22);
		cout << "■◇총잡이  | 사거리: 5칸 ■" << endl;
		gotoxy(92, 23);
		cout << "■가격 : 100| 공격력: 10  ■" << endl;
		gotoxy(92, 24);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(103, 26);
		cout << "1 / 3" << endl;
	}
	else if (page == 2)
	{
		gotoxy(92, 6);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 7);
		cout << "■◇화염마법사|사거리: 5칸■" << endl;
		gotoxy(92, 8);
		cout << "■가격: 100   |공격력: 10 ■" << endl;
		gotoxy(92, 9);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 11);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 12);
		cout << "■◇얼음마법사|사거리: 5칸■" << endl;
		gotoxy(92, 13);
		cout << "■가격: 500   |공격력: 5  ■" << endl;
		gotoxy(92, 14);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 16);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 17);
		cout << "■◇번개마법사|사거리: ∞ ■" << endl;
		gotoxy(92, 18);
		cout << "■가격: 500   |공격력: 20 ■" << endl;
		gotoxy(92, 19);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(103, 26);
		cout << "2 / 3" << endl;
	}
	else if (page == 3)
	{
		gotoxy(92, 6);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 7);
		cout << "■◇검병    | 사거리: 1칸 ■" << endl;
		gotoxy(92, 8);
		cout << "■가격: 20  | 공격력: 5   ■" << endl;
		gotoxy(92, 9);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 11);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 12);
		cout << "■◇창병    | 사거리: 1칸 ■" << endl;
		gotoxy(92, 13);
		cout << "■가격: 50  | 공격력: 2   ■" << endl;
		gotoxy(92, 14);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 16);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 17);
		cout << "■◇슬레이어 | 사거리: 1칸■" << endl;
		gotoxy(92, 18);
		cout << "■가격: 1000| 공격력: 200 ■" << endl;
		gotoxy(92, 19);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(103, 26);
		cout << "3 / 3" << endl;
	}
}

KEY KeyController()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		return KEY::LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		return KEY::RIGHT;
	}
}