#include "EnemyNPC.h"

EnemyNPC::EnemyNPC() : NonPlayerCharacter() 
{
	object_type = ObjectType::ENEMY_NPC;
	this->speed = 20;

	this->size = { 2,2 };
}