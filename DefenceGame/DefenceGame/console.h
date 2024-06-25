#pragma once
#include<Windows.h>
#include"Vector2.h"
void fullScreen();
//void gotoxy(int x, int y);
BOOL gotoxy(int x, int y);
BOOL gotoxy(const Vector2& pos);
COORD getCursorPos();
void setCursorVisible(bool vis, DWORD size);
void setColor(int txtColor = 15, int bgColor = 0);
int getColor();
void lockResize();
COORD getConsoleResolution();
void setFontSize(UINT _weight, UINT _fontx, UINT _fonty);
void lockConsoleScroll();
void lockDragAndClick();
Vector2 getMousePos();
bool getMouseInput();
enum class COLOR
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};

#include<iostream>
using std::cout;
using std::wcout;
using std::endl;