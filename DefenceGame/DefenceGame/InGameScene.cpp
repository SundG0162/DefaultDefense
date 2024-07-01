#include "InGameScene.h"
#include <fstream>
#include <Windows.h>
#include "console.h"
#include "Cell.h"
#include "Type.h"
#include "MapManager.h"
#include "EntityManager.h"
#include "WaveManager.h"
#include "IdleState.h"
#include "InGameState.h"
#include "PlaceState.h"
#include "SelectState.h"
#include "RemoveState.h"
#include "BattleState.h"
#include "AskState.h"
#include "Player.h"
#include "mci.h"

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}

void InGameScene::init()
{
	//PlayBgm(TEXT("Sounds\\InGameBGM.mp3"), 500);
	GET_SINGLETON(Player)->init();
	GET_SINGLETON(WaveManager)->initWave();
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
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::GRAY, "  " , MAP_TYPE::WALL, ROAD_TYPE::NONE }, Vector2(j, i));
				}
				else if (read == '1')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::LIGHT_GRAY, "  ", MAP_TYPE::ROAD, ROAD_TYPE::FIRST }, Vector2(j, i));
				}
				else if (read == '2')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::WHITE, "  ", MAP_TYPE::PLACE, ROAD_TYPE::NONE }, Vector2(j, i));
				}
				else if (read == '3')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::LIGHT_GRAY, "  ", MAP_TYPE::ROAD, ROAD_TYPE::SECOND }, Vector2(j, i));
				}
				else if (read == '4')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::YELLOW, "  ", MAP_TYPE::HOUSE, ROAD_TYPE::NONE }, Vector2(j, i));
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

	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::IDLE, new IdleState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::SELECT, new SelectState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::REMOVE, new RemoveState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::PLACE, new PlaceState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::BATTLE, new BattleState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::ASK, new AskState(this)));
	
	changeState(INGAMESCENE_STATE::IDLE);
}

void InGameScene::update()
{
	_currentState->update();
}

void InGameScene::render()
{
	mapRender();
	uiRender();
	_currentState->render();
}

void InGameScene::changeState(INGAMESCENE_STATE state)
{
	system("cls");
	_currentState = _stateMap[state];
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
			entityRender(pos);
		}
		gotoxy(30, 7 + i);
	}
	setColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

void InGameScene::entityRender(const Vector2& pos)
{
	cout << GET_SINGLETON(MapManager)->getCell(pos)->renderString;
}

void InGameScene::uiRender()
{
	gotoxy(1, 1);
	cout << "현재 체력 : ";
	for (int i = 0; i < GET_SINGLETON(Player)->getHP(); i++)
	{
		cout << "♥";
	}
	cout << "   ";

	gotoxy(1, 2);
	cout << "골드 : " << GET_SINGLETON(Player)->getGold();
}
