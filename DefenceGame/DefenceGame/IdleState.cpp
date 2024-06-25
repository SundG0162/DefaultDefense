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
		_inGameScene->changeState(INGAMESCENE_STATE::REMOVE);
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
	cout << "(1) 아군 구매\t\t(2)아군 삭제\t\t(3) 전투 시작!\t\t";
}