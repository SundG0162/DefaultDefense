#include "InGameScene.h"
#include <fstream>
#include <Windows.h>
#include"console.h"
#include"Cell.h"
#include"Type.h"
#include"MapManager.h"
#include"EntityManager.h"
#include"IdleState.h"
#include"InGameState.h"
#include"PlaceState.h"

InGameScene::InGameScene()
{
}

InGameScene::~InGameScene()
{
}

void InGameScene::init()
{
	GET_SINGLETON(EntityManager)->init();
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
					GET_SINGLETON(MapManager)->setCell(Cell{ COLOR::YELLOW, "  ", MAP_TYPE::WALL, ROAD_TYPE::NONE }, Vector2(j, i));
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

	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::IDLE, new IdleState()));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::PLACE, new PlaceState(this)));
	
	changeState(INGAMESCENE_STATE::PLACE);

	GET_SINGLETON(EntityManager)->spawnEntity(ALLY_TYPE::ARCHER, Vector2(3, 7));
	GET_SINGLETON(EntityManager)->spawnEntity(ENEMY_TYPE::GOBLIN, ENEMY_SPAWNPOS, ROAD_TYPE::FIRST);
}

void InGameScene::update()
{
	if (GetAsyncKeyState('A'))
	{
		GET_SINGLETON(EntityManager)->spawnEntity(ENEMY_TYPE::GOBLIN, ENEMY_SPAWNPOS, ROAD_TYPE::FIRST);
		GET_SINGLETON(EntityManager)->spawnEntity(ENEMY_TYPE::GOBLIN, ENEMY_SPAWNPOS, ROAD_TYPE::SECOND);
	}

	_currentState->update();

	entityUpdate();
}

void InGameScene::render()
{
	mapRender();
	_currentState->render();

	uiRender();
	selectUIRender();
}

void InGameScene::changeState(INGAMESCENE_STATE state)
{
	_currentState = _stateMap[state];
}

void InGameScene::entityUpdate()
{
	for (auto& entity : GET_SINGLETON(EntityManager)->getEntities())
	{
		if (entity == nullptr)
			continue;
		entity->update();
	}
	GET_SINGLETON(EntityManager)->deleteEntity();
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

void InGameScene::uiRender()
{
	gotoxy(50, 0);
	cout << " 현재 웨이브 :  " << endl;
	gotoxy(50, 1);
	cout << "남은 적 수 : " << GET_SINGLETON(EntityManager)->getEnemies().size() << endl;
}



void InGameScene::entityRender(const Vector2& pos)
{
	cout << GET_SINGLETON(MapManager)->getCell(pos)->renderString;
}

KEY InGameScene::KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		return KEY::LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		return KEY::RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		return KEY::SPACE;
	}
	return KEY::FAIL;
}