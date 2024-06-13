#pragma once
enum class ENTITY_TYPE
{
	ALLY,
	ENEMY,
	TRAP
};

class Entity
{
private:
	ENTITY_TYPE _type;
public:
	ENTITY_TYPE getType() { return _type; }
};

