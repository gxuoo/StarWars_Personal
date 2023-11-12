#include "Particle.h"

Particle::Particle() :Object() 
{
	object_type = ObjectType::PARTICLE;
	damage = 1;
	size = { 1, 1 };
}

void Particle::setDamage(const int damage) 
{
	this->damage = damage;
}

int Particle::getDamage() 
{
	return damage;
}