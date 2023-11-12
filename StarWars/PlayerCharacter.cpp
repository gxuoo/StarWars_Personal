#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter() : Character() 
{
	object_type = ObjectType::PLAYER_CHARACTER;
	jump_timer = 0;
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
	return 10;
}