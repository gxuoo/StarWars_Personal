#include "Character.h"

Character::Character() : Object() 
{
	weapon_id = 0;
	health = 100;
	buff_timer = 0;
	jump_timer = 0;
	speed = 1;
	object_type = ObjectType::CHARACTER;
	size = { 1, 2 };
}

void Character::setWeapon(int weapon_id) 
{
	this->weapon_id = weapon_id;
}

void Character::setHealth(const int health) 
{
	this->health = health;
}

void Character::addHealth(const int health) 
{
	this->health += health;
}

void Character::giveDamage(const int damage) 
{
	this->health -= damage;
}

int Character::getWeapon()
{
	return weapon_id;
}
void Character::setBuffTimer(const int time) 
{
	buff_timer = time;
}

int  Character::getBuffTimer() 
{
	return buff_timer;
}

void Character::setJumpTimer(const int time) 
{
	jump_timer = time;
}

int Character::getJumpTimer() 
{
	return jump_timer;
}

int Character::getJumpLimit() 
{
	return JUMPLIMIT;
}