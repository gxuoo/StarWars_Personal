#include "Character.h"


Character::Character() : Object() 
{
	weapon_id = 0;
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

std::string Character::getWeaponName()
{
	switch (weapon_id)
	{
	case 1 :
		return "±ÇÃÑ";
		break;
	case 2 :
		return "µ¹°Ý¼ÒÃÑ";
		break;
	case 3:
		return "°Ë";
		break;
	case 4:
		return "¼¦°Ç";
		break;
	case 5:
		return "Àú°ÝÃÑ";
		break;
	default :
		return "ÁÖ¸Ô";
	}
}

std::string Character::getBuffName()
{
	switch (this->current_buff)
	{
	case 1:
		return "¼Óµµ x1.5";
		break;
	case 2:
		return "¾ó·ÁÁü!";
		break;
	default:
		return "¾øÀ½";
	}
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
	return DroppedWeapon::getSpeed(weapon_id);
}

int Character::getWeaponDamage()
{
	return DroppedWeapon::getDamage(weapon_id);
}

int Character::getWeaponRPM()
{
	return DroppedWeapon::getRPM(weapon_id);
}

int Character::getWeaponMaxRange()
{
	return DroppedWeapon::getMaxRange(weapon_id);
}

bool Character::isWeaponMelee()
{
	return DroppedWeapon::isMelee(weapon_id);
}

bool Character::isWeaponShotgun()
{
	return DroppedWeapon::isShotgun(weapon_id);
}