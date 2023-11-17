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
		return 15;
		break;
	case 4://shotgun
		return 5;
		break;
	case 5 ://sniper
		return 20;
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
		return 3;
		break;
	case 2://rifle
		return  6;
		break;
	case 3://sword
		return 1;
		break;
	case 4://shotgun
		return 4;
		break;
	case 5://sniper
		return 20;
		break;
	default://fist
		return 1;
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
		return 5;
		break;
	case 4://shotgun
		return 2;
		break;
	case 5://sniper
		return 2;
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

void DroppedWeapon::useItem(Object* itemuser, Object* elseuser) {
	((Character*)itemuser)->setWeapon(weapon_id);
}

