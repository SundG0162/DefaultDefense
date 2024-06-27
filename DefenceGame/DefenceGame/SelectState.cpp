#include "SelectState.h"
#include "Player.h"
#include<conio.h>

SelectState::SelectState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}
void SelectState::update()
{
	KEY Key = keyController();
	switch (Key)
	{
	case KEY::ONE:
	{
		_currentSelectIndex = 1;
		break;
	}
	case KEY::TWO:
	{
		_currentSelectIndex = 2;
		break;
	}
	case KEY::THREE:
	{
		_currentSelectIndex = 3;
		break;
	}
	case KEY::FOUR:
	{
		_currentSelectIndex = 4;
		break;
	}
	case KEY::RIGHT:
	{
		if (_currentPage < 3)
			_currentPage++;
		break;
	}
	case KEY::LEFT:
	{
		if (_currentPage > 1)
			_currentPage--;
		break;
	}
	case KEY::UP:
	{
		if (_currentSelectIndex > 1)
			_currentSelectIndex--;
		break;
	}
	case KEY::DOWN:
	{
		if (_currentSelectIndex < 4)
			_currentSelectIndex++;
		break;
	}
	case KEY::ENTER:
	{
		spawnAlly();
		break;
	}
	case KEY::SPACE:
	{
		spawnAlly();
		break;
	}
	case KEY::ESC:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
		break;
	}
	}
}

void SelectState::render()
{
	if (_currentPage == 1)
	{
		gotoxy(92, 6);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 7);
		cout << "■  궁수    | 사거리: 3칸 ■" << endl;
		gotoxy(92, 8);
		cout << "■가격: 20  | 공격력: 5   ■" << endl;
		gotoxy(92, 9);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 11);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 12);
		cout << "■  석궁병  | 사거리: 5칸 ■" << endl;
		gotoxy(92, 13);
		cout << "■가격: 50  | 공격력: 1   ■" << endl;
		gotoxy(92, 14);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 16);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 17);
		cout << "■  발리스타| 사거리: 10칸■" << endl;
		gotoxy(92, 18);
		cout << "■가격: 1000| 공격력: 200 ■" << endl;
		gotoxy(92, 19);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 21);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 22);
		cout << "■  총잡이  | 사거리: 5칸 ■" << endl;
		gotoxy(92, 23);
		cout << "■가격 : 100| 공격력: 10  ■" << endl;
		gotoxy(92, 24);
		cout << "■■■■■■■■■■■■■■" << endl << endl;
	}
	else if (_currentPage == 2)
	{
		gotoxy(92, 6);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 7);
		cout << "■  화염마법사|사거리: 5칸■" << endl;
		gotoxy(92, 8);
		cout << "■가격: 100   |공격력: 10 ■" << endl;
		gotoxy(92, 9);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 11);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 12);
		cout << "■  얼음마법사|사거리: 5칸■" << endl;
		gotoxy(92, 13);
		cout << "■가격: 500   |공격력: 5  ■" << endl;
		gotoxy(92, 14);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 16);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 17);
		cout << "■  번개마법사|사거리: ∞ ■" << endl;
		gotoxy(92, 18);
		cout << "■가격: 500   |공격력: 20 ■" << endl;
		gotoxy(92, 19);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 21);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 22);
		cout << "■  네크로맨서|사거리: ?칸■" << endl;
		gotoxy(92, 23);
		cout << "■가격 : 500| 공격력: ??  ■" << endl;
		gotoxy(92, 24);
		cout << "■■■■■■■■■■■■■■" << endl << endl;
	}
	else if (_currentPage == 3)
	{
		gotoxy(92, 6);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 7);
		cout << "■  검병    | 사거리: 1칸 ■" << endl;
		gotoxy(92, 8);
		cout << "■가격: 50  | 공격력: 5   ■" << endl;
		gotoxy(92, 9);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 11);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 12);
		cout << "■  창병    | 사거리: 2칸 ■" << endl;
		gotoxy(92, 13);
		cout << "■가격: 80  | 공격력: 7   ■" << endl;
		gotoxy(92, 14);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 16);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 17);
		cout << "■  슬레이어 | 사거리: 1칸■" << endl;
		gotoxy(92, 18);
		cout << "■가격: 1000| 공격력: 200 ■" << endl;
		gotoxy(92, 19);
		cout << "■■■■■■■■■■■■■■" << endl << endl;

		gotoxy(92, 21);
		cout << "■■■■■■■■■■■■■■" << endl;
		gotoxy(92, 22);
		cout << "■  대검병  | 사거리: 2칸 ■" << endl;
		gotoxy(92, 23);
		cout << "■가격 : 800| 공격력: 300 ■" << endl;
		gotoxy(92, 24);
		cout << "■■■■■■■■■■■■■■" << endl << endl;
	}

	gotoxy(103, 26);
	cout << _currentPage << " / 3" << endl;

	int selectMarkY = 7 + 5 * (_currentSelectIndex - 1);
	gotoxy(93, selectMarkY);
	cout << "◆";

	gotoxy(51, 26);
	cout << "ESC키를 눌러 취소";
	gotoxy(48, 27);
	cout << "Enter 또는 Space키로 고용";
}

void SelectState::spawnAlly()
{
	Ally* ally =
		GET_SINGLETON(EntityManager)->
		spawnEntity((ALLY_TYPE)(((_currentPage - 1) * 4) + _currentSelectIndex), Vector2(28, 19));

	if (GET_SINGLETON(Player)->getGold() < ally->getPrice())
	{
		setColor((int)COLOR::RED);
		gotoxy(51, 28);
		cout << "돈이 부족합니다!";
		setColor();
		GET_SINGLETON(EntityManager)->despawnEntity(ally);
	}
	else
	{
		GET_SINGLETON(Player)->modifyGold(-ally->getPrice());
		GET_SINGLETON(Player)->setAlly(ally);
		_inGameScene->changeState(INGAMESCENE_STATE::PLACE);
	}
}
