#include "Character.h"


Character::Character() : Object() 
{
	weapon_id = 0;
	weapon_damage = DroppedWeapon::getDamage(weapon_id);
	weapon_speed = DroppedWeapon::getSpeed(weapon_id);
	isFreeze = false;
	health = 100;
	buff_timer = 0;
	speed = 1;
	object_type = ObjectType::CHARACTER;
	size = { 1, 2 };
	direction = 0;
	bullet_count = 0;
	last_shot = 0;
	current_buff = 0;
}

void Character::setWeapon(int weapon_id) 
{
	this->weapon_id = weapon_id;
	weapon_damage = DroppedWeapon::getDamage(weapon_id);
	weapon_speed = DroppedWeapon::getSpeed(weapon_id);
	bullet_count = DroppedWeapon::getBulletCount(weapon_id);
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

int Character::getBuffTimer() 
{
	return buff_timer;
}

int Character::getHealth()
{
	return this->health;
}

int Character::getWeaponSpeed()
{
	return weapon_speed;
}

int Character::getWeaponDamage()
{
	return weapon_damage;
}

void Character::setWeaponSpeed(int weapon_speed)
{
	this->weapon_speed = weapon_speed;
}

void Character::setWeaponDamage(int weapon_damage)
{
	this->weapon_damage = weapon_damage;
}