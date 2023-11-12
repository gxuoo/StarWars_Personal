#include "Object.h"

Object::Object() : Object(false, { 0, 0 }, {0, 0})
{
}

Object::Object(bool isFixed, Vec2 coord, Vec2 size) : isFixed(isFixed), coord(coord), size(size)
{
	velocity = 0;
	nextCoord = coord;
	object_type = ObjectType::OBJECT;
	delete_object = false;
}

Vec2& Object::GetCoord() 
{
	return this->coord;
}

Vec2& Object::GetVelocity() 
{
	return this->velocity;
}

Vec2& Object::GetNextCoord()
{
	return this->nextCoord;
}

bool& Object::GetDeleteObject()
{
	return this->delete_object;
}

int Object::GetSpeed()
{
	return this->speed;
}

ObjectType Object::getObjectType() 
{
	return object_type;
}

void Object::SetVelocity(const Vec2& c) 
{
	this->velocity = c;
}

void Object::SetNextCoord(const Vec2& c)
{
	this->nextCoord = c;
}

void Object::SetCoord(const Vec2& c) 
{
	this->coord = c;
}

void Object::SetSpeed(int speed) 
{
	this->speed = speed;
}

void Object::SetDeleteObject(bool delete_object)
{
	this->delete_object = delete_object;
}

bool Object::IsCharacter() 
{
	if (this->object_type == ObjectType::ENEMY_NPC || this->object_type == ObjectType::FRIENDLY_NPC || this->object_type == ObjectType::PLAYER_CHARACTER || this->object_type == ObjectType::NON_PLAYER_CHARACTER || this->object_type == ObjectType::CHARACTER)
		return true;

	return false;
}

bool Object::IsItem() 
{
	if (this->object_type == ObjectType::DROPPED_ITEM || this->object_type == ObjectType::DROPPED_SPECIAL_ITEM || this->object_type == ObjectType::DROPPED_WEAPON)
		return true;

	return false;
}

int Object::GetCollisionPriority() {//오브젝트의 Type에 따라 우선순위를 반환함. 우선순위가 1 에 가까울수록 우선순위가 높음.
	if (this->object_type == ObjectType::WALL)
	{
		return 1;
	}

	else if (this->IsCharacter())
	{
		return 2;
	}
	
	else if (this->IsItem()) 
	{
		return 3;
	}
	
	else if (this->object_type == ObjectType::PARTICLE) 
	{
		return 4;
	}
	
	else 
	{
		return 0;
	}

}

bool Object::IsCollisionWith(const Object& obj) 
{
	Vec2 object1_size = this->size;
	Vec2 object2_size = obj.size;

	for (int i = 0; i < object1_size.getX(); ++i)
	{
		for (int j = 0; j < object1_size.getY(); ++j)
		{
			if (this->nextCoord + Vec2{ i, j } == obj.nextCoord || this->coord + Vec2{ i, j } == obj.coord)
				return true;

			return false;
		}
	}

	for (int i = 0; i < object2_size.getX(); ++i)
	{
		for (int j = 0; j < object2_size.getY(); ++j)
		{
			if (this->nextCoord == obj.nextCoord + Vec2{ i, j } || this->coord == obj.coord + Vec2{ i, j })
				return true;

			return false;
		}
	}

	return false;
}
