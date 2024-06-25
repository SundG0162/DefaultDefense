#include<Windows.h>
#include "console.h"

void fullScreen()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

//void gotoxy(int x, int y)
//{
//	COORD cursor = { x,y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
//}

BOOL gotoxy(int x, int y)
{
	COORD cursor = { x,y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

BOOL gotoxy(const Vector2& pos)
{
	COORD cursor = { pos.x,pos.y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}



COORD getCursorPos()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.dwCursorPosition;
}

void setCursorVisible(bool vis, DWORD size)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = vis; // true : On, false : Off
	curInfo.dwSize = size; // Ä¿¼­ ±½±â (1~100)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void setColor(int txtColor, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | txtColor);
}


int getColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	int color = info.wAttributes & 0xf;
	return color;
}

void lockResize()
{
	HWND console = GetConsoleWindow();

	if (console != nullptr)
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
		SetWindowLong(console, GWL_STYLE, style);
	}
}

COORD getConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;


	return COORD{ width, height };
}

void setFontSize(UINT _weight, UINT _fontx, UINT _fonty)
{
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _fontx;
	font.dwFontSize.Y = _fonty;
	SetCurrentConsoleFontEx(hout, false, &font);
}

void lockConsoleScroll()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) return;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

	SMALL_RECT windowSize = csbi.srWindow;
	COORD bufferSize = { windowSize.Right - windowSize.Left + 1, windowSize.Bottom - windowSize.Top + 1 };

	SetConsoleScreenBufferSize(hConsole, bufferSize);
}

void lockDragAndClick()
{
	DWORD consoleModePrev;
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(handle, &consoleModePrev);
	SetConsoleMode(handle, consoleModePrev & ~ENABLE_QUICK_EDIT_MODE);
}

Vector2 getMousePos()
{
	Vector2 mousePos = Vector2();
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

		mousePos = Vector2(cellX, cellY);
	}
	return mousePos;
}

bool getMouseInput()
{
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
			return mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;
		}
	}
	return false;
}
