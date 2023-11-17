#include "Particle.h"

Particle::Particle() :Object() 
{
	object_type = ObjectType::PARTICLE;
	damage = 1;
	size = { 1, 1 };
	shooter = NULL;
	max_range = 1;
	cur_range = 0;
	isMelee = false;
	isShotgun = false;
}

void Particle::setDamage(const int damage) 
{
	this->damage = damage;
}

int Particle::getDamage() 
{
	return damage;
}