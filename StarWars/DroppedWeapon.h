#pragma once

#include "DroppedItem.h"
#include "Character.h"

#ifndef DROPPED_WEAPON_HPP
#define DROPPED_WEAPON_HPP

class DroppedWeapon : DroppedItem {
public:
	DroppedWeapon();
	DroppedWeapon(int w_id);
	~DroppedWeapon() = default;
	static int getDamage(int weapon_id);
	static int getSpeed(int weapon_id);
	void useItem(Object* itemuser, Object* elseuser);
private:
	int weapon_id;
	int damage;
	int speed;
	const int TOTAL_WEAPON = 3;// 0 : ¡÷∏‘, 1 : ±«√—, 2 : µπ∞›º“√—
};

#endif