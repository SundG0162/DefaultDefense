#include "AskState.h"
#include "Define.h"
#include "SceneManager.h"
#include "console.h"
AskState::AskState(InGameScene* inGameScene)
{
	_inGameScene = inGameScene;
}

void AskState::update()
{
	KEY key = keyController();

	switch (key)
	{
	case KEY::SPACE:
	case KEY::ENTER:
		GET_SINGLETON(SceneManager)->setTransition("TitleScene");
		GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
		break;
	case KEY::ESC:
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
		break;
	}
}

void AskState::render()
{
	gotoxy(37, 0);
	cout << "정말 나가시겠습니까? (ENTER or SPACE를 눌러 나가기)";
	gotoxy(45, 1);
	cout << "결과창을 확인하실 수 없습니다.";
	gotoxy(50, 2);
	cout << "ESC키를 눌러 취소";
}
