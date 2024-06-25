#include "PlaceState.h"
#include"Vector2.h"
#include<Windows.h>
#include"MapManager.h"
#include"Define.h"
#include"Player.h"
#include"EntityManager.h"


void PlaceState::update()
{
	HWND consoleWindow = GetConsoleWindow();
	HDC hdc = GetDC(consoleWindow);

	RECT clientRect;
	GetClientRect(consoleWindow, &clientRect);
	POINT clientTopLeft = { clientRect.left, clientRect.top };
	ClientToScreen(consoleWindow, &clientTopLeft);

	CONSOLE_FONT_INFO fontInfo;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFont(hConsoleOutput, FALSE, &fontInfo);
	COORD fontSize = GetConsoleFontSize(hConsoleOutput, fontInfo.nFont);

	POINT p;

	if (GetCursorPos(&p)) {
		ScreenToClient(consoleWindow, &p);

		int cellX = (p.x - clientRect.left) / fontSize.X;
		int cellY = (p.y - clientRect.top) / fontSize.Y;

		Vector2 mousePos(cellX, cellY);
		_currentMousePos = GET_SINGLETON(MapManager)->consolePosToCellPos(mousePos);
	}

	DWORD consoleModePrev;
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hConsoleInput, &consoleModePrev);
	DWORD consoleMode = consoleModePrev & ~ENABLE_QUICK_EDIT_MODE;
	consoleMode |= ENABLE_MOUSE_INPUT;
	SetConsoleMode(hConsoleInput, consoleMode);
	INPUT_RECORD inputRecord;
	DWORD events;

	ReadConsoleInput(hConsoleInput, &inputRecord, 1, &events);

	if (inputRecord.EventType == MOUSE_EVENT) {
		MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;

		if (mouseEvent.dwEventFlags == 0)
		{
			if (mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				if (!isInMap(_currentMousePos)) return;
				if (!isCellEmpty()) return;
				Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
				if (cell->type != MAP_TYPE::PLACE)
					return;
				GET_SINGLETON(Player)->getAlly()->setPos(_currentMousePos);
				_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
			}
		}
	}

}

void PlaceState::render()
{
	gotoxy(40, 0);
	cout << "원하는 곳에 마우스를 클릭하여 아군을 설치하세요.";
	gotoxy(43, 1);
	cout << "설치 가능한 위치에서 ★로 표시됩니다.";
	if (!isInMap(_currentMousePos)) return;
	if (!isCellEmpty()) return;
	Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
	if (cell->type != MAP_TYPE::PLACE)
		return;
	setColor((int)COLOR::BLACK, (int)cell->bgColor);
	gotoxy(GET_SINGLETON(MapManager)->cellPosToConsolePos(_currentMousePos));
	cout << "★";
	setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

bool PlaceState::isInMap(const Vector2& pos)
{
	bool isXIn = _currentMousePos.x >= 0 && _currentMousePos.x < MAP_WIDTH;
	bool isYIn = _currentMousePos.y >= 0 && _currentMousePos.y < MAP_HEIGHT;
	return isYIn && isXIn;
}

bool PlaceState::isCellEmpty()
{
	return GET_SINGLETON(MapManager)->getCell(_currentMousePos)->getEntities().size() == 0;
}