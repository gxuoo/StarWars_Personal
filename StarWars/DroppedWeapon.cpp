#include "DroppedWeapon.h"

DroppedWeapon::DroppedWeapon() : DroppedWeapon(0)
{
}

DroppedWeapon::DroppedWeapon(int w_id) : DroppedItem() 
{
	object_type = ObjectType::DROPPED_WEAPON;
	weapon_id = w_id;
}

void DroppedWeapon::useItem(Object* itemuser) {
	((Character*)itemuser)->setWeapon(weapon_id);
}

