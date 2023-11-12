#include "Wall.h"

Wall::Wall() :Object() 
{
	object_type = ObjectType::WALL;
	size = { 1, 1 };
}