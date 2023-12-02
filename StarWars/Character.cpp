#include "Character.h"


Character::Character() : Object() 
{
	weapon_id = 0;
	isFreeze = false;
	is_attacked = false;
	health = 100;
	buff_timer = 0;
	hit_timer = 0;
	speed = 1;
	object_type = ObjectType::CHARACTER;
	size = { 1, 2 };
	direction = { 0, 0 };
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
		return "����";
		break;
	case 2 :
		return "���ݼ���";
		break;
	case 3:
		return "��";
		break;
	case 4:
		return "����";
		break;
	case 5:
		return "������";
		break;
	case 6:
		return "��ǳ";
		break;
	default :
		return "�ָ�";
	}
}

std::string Character::getBuffName()
{
	switch (this->current_buff)
	{
	case 1:
		return "�ӵ� x1.5";
		break;
	case 2:
		return "�����!";
		break;
	default:
		return "����";
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

void Character::SetHitTimer(const int time)
{
	hit_timer = time;
}

int Character::GetHitTimer()
{
	return hit_timer;
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

bool Character::isWeaponHatoken()
{
	return DroppedWeapon::isHatoken(weapon_id);
}