#include "IdleState.h"
#include"InGameScene.h"
#include<conio.h>
#include"console.h"
#include"WaveManager.h"

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
		_inGameScene->changeState(INGAMESCENE_STATE::BATTLE);
		GET_SINGLETON(WaveManager)->nextWave();
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
	gotoxy(49, 0);
	cout << " 다음 웨이브 :  " << GET_SINGLETON(WaveManager)->getCurrentWave() + 1;
	gotoxy(27, 27);
	cout << "(1) 아군 고용\t\t(2) 아군 방출\t\t(3) 전투 시작!\t\t";
}