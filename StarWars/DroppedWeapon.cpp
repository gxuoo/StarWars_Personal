#include "DroppedWeapon.h"

DroppedWeapon::DroppedWeapon() : DroppedWeapon(0)
{
}

DroppedWeapon::DroppedWeapon(int w_id) : DroppedItem() 
{
	object_type = ObjectType::DROPPED_WEAPON;
	weapon_id = w_id;
	damage = getDamage(weapon_id);
	speed = getSpeed(weapon_id);
	RPM = getRPM(weapon_id);
	max_range = getMaxRange(weapon_id);
}

int DroppedWeapon::getDamage(int weapon_id)
{
	switch (weapon_id)
	{
	case 1://pistol
		return 5;
		break;
	case 2://rifle
		return 8;
		break;
	case 3://sword
		return 7;
		break;
	case 4://shotgun
		return 15;
		break;
	case 5 ://sniper
		return 20;
		break;
	case 6://Hatoken
		return 10;
		break;
	default://fist
		return 3;
		break;
	}

}
int DroppedWeapon::getSpeed(int weapon_id)
{
	switch (weapon_id)
	{
	case 1://pistol
		return 25;
		break;
	case 2://rifle
		return 40;
		break;
	case 3://sword
		return 25;
		break;
	case 4://shotgun
		return 30;
		break;
	case 5://sniper
		return 1000;
		break;
	case 6:
		return 30;
		break;
	default://fist
		return 25;
		break;
	}
}

int DroppedWeapon::getBulletCount(int weapon_id)
{
	switch (weapon_id)
	{
	case 1://pistol
		return 20;
		break;
	case 2://rifle
		return 60;
		break;
	case 3://sword
		return 10;
		break;
	case 4://shotgun
		return 15;
		break;
	case 5://sniper
		return 10;
		break;
	case 6://Hatoken
		return 10;
		break;
	default :
		return 0;
	}
}

int DroppedWeapon::getRPM(int weapon_id)
{
	switch (weapon_id)
	{
	case 1://pistol
		return 5;
		break;
	case 2://rifle
		return 10;
		break;
	case 3: //sword
		return 3;
		break;
	case 4://shotgun
		return 2;
		break;
	case 5://sniper
		return 2;
		break;
	case 6://Hatoken 
		return 5;
		break;
	default://fist
		return 5;
		break;
	}
}

int DroppedWeapon::getMaxRange(int weapon_id)
{
	switch (weapon_id)
	{
	case 1://pistol
		return 10;
		break;
	case 2://rifle
		return  20;
		break;
	case 3 : // sword
		return 0;
		break;
	case 4://shotgun
		return 7;
		break;
	case 5://sniper
		return 40;
		break;
	case 6://Hatoken
		return 10;
		break;
	default://fist
		return 0;
		break;
	}
}

bool DroppedWeapon::isMelee(int weapon_id)
{
	switch (weapon_id)
	{
	case 0 : case 3 :
		return true;
	default :
		return false;
	}
}

bool DroppedWeapon::isShotgun(int weapon_id)
{
	switch (weapon_id)
	{
	case 4 :
		return true;
	default :
		return false;
	}
}

bool DroppedWeapon::isHatoken(int weapon_id)
{
	switch (weapon_id)
	{
	case 6:
		return true;
	default:
		return false;
	}
}

void DroppedWeapon::useItem(Object* itemuser, Object* elseuser, vector< Object*>& objects) {
	((Character*)itemuser)->setWeapon(weapon_id);
}

