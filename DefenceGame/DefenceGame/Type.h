#pragma once
enum class MAP_TYPE
{
	WALL,
	ROAD,
	PLACE
};
enum class ENTITY_TYPE
{
	ALLY,
	ENEMY,
	TRAP
};

enum class ROAD_TYPE
{
	FIRST,
	SECOND,
	NONE
};

enum class ALLY_TYPE
{
	ARCHER = 1
};

enum class ENEMY_TYPE
{
	GOBLIN = 1
};

enum class TRAP_TYPE
{
	DEFAULT
};

enum class INGAMESCENE_STATE
{
	IDLE,
	SELECT,
	PLACE,
	BATTLE,
	NONE
};