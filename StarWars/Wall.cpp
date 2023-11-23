#include "Wall.h"

Wall::Wall() :Object() 
{
	health = 50;
	object_type = ObjectType::WALL;
	size = { 1, 1 };
}

void Wall::giveDamage(const int damage)
{
	this->health -= damage;
}

int Wall::getHealth()
{
	return this->health;
}