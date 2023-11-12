#include "DroppedSpecialItem.h"

DroppedSpecialItem::DroppedSpecialItem() : DroppedSpecialItem(0)
{

}

DroppedSpecialItem::DroppedSpecialItem(int item_id) : DroppedItem() 
{
	special_item_id = item_id;
	object_type = ObjectType::DROPPED_SPECIAL_ITEM;
}

void DroppedSpecialItem::useItem(Object* itemuser) 
{
	const int PLAYER_MAX_HEALTH = 100;
	
	switch (special_item_id) 
	{
	case 0:
		((Character*)itemuser)->addHealth(PLAYER_MAX_HEALTH * 30 / 100);
		break;

	case 1:
		((Character*)itemuser)->setBuffTimer(10);
		((Character*)itemuser)->SetSpeed(2);
		break;
	
	case 3:
		break;
	}
}