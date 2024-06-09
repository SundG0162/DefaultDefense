#include "InGameScene.h"
#include <fstream>
#include <Windows.h>
#include"console.h"

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}

void InGameScene::init()
{
	std::fstream mapRead("Map\\Map1.txt");
	if (mapRead.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			mapRead.getline(arrMap[i], MAP_WIDTH);
			if (mapRead.fail())
			{
				cout << "File Read Fail. Please Check the directory.";
				break;
			}
		}
	}
	mapRead.close();

}

void InGameScene::update()
{

}

void InGameScene::render()
{
	gotoxy(0, 0);
	for(int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if (arrMap[i][j] == '0')
			{
				cout << "¡á";
			}
			if (arrMap[i][j] == '1')
			{
				cout << "  ";
			}
			if (arrMap[i][j] == '2')
			{
				cout << "¢Ã";
			}
			if (arrMap[i][j] == '4')
			{
				cout << "¢Ë";
			}
		}
		cout << std::endl;
	}
}
