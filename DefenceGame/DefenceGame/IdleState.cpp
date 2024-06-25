#include "IdleState.h"
#include"InGameScene.h"
#include<conio.h>
#include"console.h"

IdleState::IdleState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}

void IdleState::update()
{
	KEY Key = keyController();
	switch (Key)
	{
	case KEY::ONE:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::SELECT);
		break;
	}
	case KEY::TWO:
	{
		break;
	}
	case KEY::THREE:
	{
		break;
	}
	case KEY::FOUR:
	{
		break;
	}
	}
}

void IdleState::render()
{
	gotoxy(40, 27);
	cout << "(1) 아군 구매\t\t(2) 전투 시작!";
}

KEY IdleState::keyController()
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
