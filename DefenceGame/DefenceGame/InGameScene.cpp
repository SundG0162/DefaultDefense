#include "InGameScene.h"
#include <fstream>
#include <Windows.h>
#include"console.h"
#include"Cell.h"
#include"MapManager.h"

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
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				char read = mapRead.get();

				if (read == '0')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::GRAY , "  " }, j, i);
				}
				else if (read == '1')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::LIGHT_GRAY, "  " }, j, i);
				}
				else if (read == '2')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::LIGHT_BLUE, "  " }, j, i);
				}
				else if (read == '4')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::YELLOW, "  " }, j, i);
				}

				if (mapRead.fail())
				{
					cout << "File read error.";
					break;
				}
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
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			setColor((int)COLOR::WHITE, (int)GET_SINGLETON(MapManager)->getCell(j,i)->bgColor);
			cout << GET_SINGLETON(MapManager)->getCell(j,i)->renderString;
		}
		cout << std::endl;
	}
	setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}
