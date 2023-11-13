#include "DroppedSpecialItem.h"

DroppedSpecialItem::DroppedSpecialItem() : DroppedSpecialItem(0)
{

}

DroppedSpecialItem::DroppedSpecialItem(int item_id) : DroppedItem() 
{
	special_item_id = item_id;
	object_type = ObjectType::DROPPED_SPECIAL_ITEM;
}

void DroppedSpecialItem::useItem(Object* itemuser, Object* elseuser)
{
	const int PLAYER_MAX_HEALTH = 100;
	
	switch (special_item_id) 
	{
	case 0:
		((Character*)itemuser)->addHealth(PLAYER_MAX_HEALTH * 30 / 100);
		break;

	case 1:
		((Character*)itemuser)->setBuffTimer(200);
		((Character*)itemuser)->SetSpeed(30);
		((Character*)itemuser)->current_buff = 1;
		break;
	
	case 2:
		((Character*)elseuser)->setBuffTimer(100);
		((Character*)elseuser)->isFreeze = true;
		((Character*)elseuser)->current_buff = 2;
		break;
	}
}