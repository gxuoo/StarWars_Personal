#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() : Character() 
{
	object_type = ObjectType::PLAYER_CHARACTER;
	jump_timer = 0;
	is_mid_air = false;
	life = 3;
}

void PlayerCharacter::setJumpTimer(const int time)
{
	jump_timer = time;
}

int PlayerCharacter::getJumpTimer()
{
	return jump_timer;
}

int PlayerCharacter::getJumpLimit()
{
	return 5;
}