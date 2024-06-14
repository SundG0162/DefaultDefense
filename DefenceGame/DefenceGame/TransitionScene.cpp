#include "TransitionScene.h"
#include <Windows.h>
#include <iostream>
#include "console.h"
#include "Define.h"
#include "SceneManager.h"

using namespace std;

TransitionScene::~TransitionScene() {}

TransitionScene::TransitionScene() {}

void TransitionScene::init()
{
}
void TransitionScene::update()
{
}

void TransitionScene:: render()
{
    COORD Resolution = getConsoleResolution();
    int width = Resolution.X;
    int height = Resolution.Y;
    int animtime = 50;

    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::RED);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::LIGHT_RED);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::YELLOW);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::GREEN);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::LIGHT_BLUE);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::BLUE);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::BLACK, (int)COLOR::LIGHT_VIOLET);
    system("cls");
    Sleep(animtime);
    gotoxy(0, 0);
    setColor((int)COLOR::WHITE);
    system("cls");
    Sleep(animtime);

    animtime -= 30;

    setColor((int)COLOR::BLACK, (int)COLOR::WHITE);
    for (int i = 0; i < width / 2; ++i)
    {
        for (int j = 0; j < height; j += 2)
        {
            gotoxy(i * 2, j);
            cout << "  ";
        }
        for (int j = 1; j < height; j += 2)
        {
            gotoxy(width - 2 - i * 2, j);
            cout << "  ";
        }
        Sleep(animtime);
    }
    setColor((int)COLOR::WHITE);
    system("cls");

    GET_SINGLETON(SceneManager)->loadScene(GET_SINGLETON(SceneManager)->getTransitionScene());
}