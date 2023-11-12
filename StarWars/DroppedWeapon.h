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
	void useItem(Object* itemuser);
private:
	int weapon_id;
	const int TOTAL_WEAPON = 3;// 0 : ¡÷∏‘, 1 : ±«√—, 2 : µπ∞›º“√—
};

#endif