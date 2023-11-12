#pragma once

#include "Vec2.h"

#ifndef OBJECT_HPP
#define OBJECT_HPP

enum class ObjectType {
	OBJECT,
	CHARACTER,
	NON_PLAYER_CHARACTER,
	ENEMY_NPC, FRIENDLY_NPC,
	PLAYER_CHARACTER,
	DROPPED_ITEM,
	DROPPED_SPECIAL_ITEM, DROPPED_WEAPON,
	PARTICLE,
	WALL
};

class Object {
public:
	Object();
	Object(bool, Vec2, Vec2, Vec2, int);
	virtual ~Object() = default;
	Vec2& GetCoord();
	Vec2& GetVelocity();
	Vec2& GetNextCoord();
	bool& GetDeleteObject();
	int GetSpeed();
	void SetVelocity(const Vec2&);
	void SetNextCoord(const Vec2&);
	void SetDeleteObject(bool);
	void SetCoord(const Vec2&);
	void SetSpeed(int);
	bool IsCollisionWith(const Object*);
	ObjectType getObjectType();
	bool IsCharacter();
	bool IsItem();
	int GetCollisionPriority();

protected:
	bool isFixed;
	ObjectType object_type = ObjectType::OBJECT;
	Vec2 coord;
	Vec2 nextCoord;
	Vec2 velocity;
	Vec2 size;
	int speed;
	bool delete_object;
};

#endif