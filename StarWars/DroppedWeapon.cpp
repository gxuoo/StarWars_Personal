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
}

int DroppedWeapon::getDamage(int weapon_id)
{
	switch (weapon_id)
	{
	case 1://pistol
		return 5;
	case 2://rifle
		return 8;
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
	case 2://rifle
		return  6;
	default://fist
		return 3;
		break;
	}
}

int DroppedWeapon::getBulletCount(int weapon_id)
{
	switch (weapon_id)
	{
	case 1:
		return 20;
	case 2:
		return 60;
	case 3:
		return 0;
	}
}

void DroppedWeapon::useItem(Object* itemuser, Object* elseuser) {
	((Character*)itemuser)->setWeapon(weapon_id);
	((Character*)itemuser)->setWeaponDamage(damage);
	((Character*)itemuser)->setWeaponSpeed(speed);
}

