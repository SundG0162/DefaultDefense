#include "InGameScene.h"
#include <fstream>
#include <Windows.h>
#include"console.h"
#include"Cell.h"
#include"MapManager.h"
#include"EntityManager.h"
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
		for (int i = 0; i < MAP_HEIGHT - 1; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				char read = mapRead.get();

				if (read == '0')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::GRAY , "  " , MAP_TYPE::WALL}, Vector2(j, i));
				}
				else if (read == '1')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::LIGHT_GRAY, "  ", MAP_TYPE::ROAD }, Vector2(j, i));
				}
				else if (read == '2')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::BLUE, "  ", MAP_TYPE::PLACE}, Vector2(j, i));
				}
				else if (read == '4')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::YELLOW, "  ", MAP_TYPE::WALL}, Vector2(j, i));
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
	enemyMove();
	if (GetAsyncKeyState('A'))
	{
		GET_SINGLETON(EntityManager)->spawnEntity(ENEMY_TYPE::GOBLIN, Vector2(0, 10));
	}
}

void InGameScene::render()
{
	mapRender();
}

void InGameScene::enemyMove()
{
	for (auto& i : GET_SINGLETON(EntityManager)->getEnemies())
	{
		i->tryMove();
	}
}

void InGameScene::mapRender()
{
	gotoxy(30, 6);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			Vector2 pos = Vector2(j, i);
			Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
			setColor((int)cell->charColor, (int)cell->bgColor);
			entityRender(Vector2(j, i));
		}
		gotoxy(30, 7 + i);
	}
	setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

void InGameScene::entityRender(const Vector2& pos)
{
	cout << GET_SINGLETON(MapManager)->getCell(pos)->renderString;
}