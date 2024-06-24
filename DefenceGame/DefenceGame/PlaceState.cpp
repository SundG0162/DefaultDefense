#include "PlaceState.h"
#include"Vector2.h"
#include<Windows.h>
#include"MapManager.h"
#include"Define.h"
#include"Player.h"


PlaceState::PlaceState()
{
}

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
}

void PlaceState::render()
{
	Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
	if (cell->type != MAP_TYPE::PLACE)
		return;
	gotoxy(GET_SINGLETON(MapManager)->cellPosToConsolePos(_currentMousePos));
	setColor((int)COLOR::WHITE, (int)cell->bgColor);
	cout << "¡Ú";
	setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}
