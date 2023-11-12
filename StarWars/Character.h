#pragma once

#include "Object.h"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character : public Object {
public:
	Character();
	~Character() = default;
	void setHealth(const int h);
	void addHealth(const int h);
	void giveDamage(const int d);
	void setWeapon(const int w_id);
	int getWeapon();
	void setBuffTimer(const int t);
	int getBuffTimer();
	int getHealth();

protected:
	int speed;
	int health;
	int weapon_id;
	int buff_timer;
};

#endif