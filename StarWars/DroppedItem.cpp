#include "DroppedItem.h"

DroppedItem::DroppedItem() : Object() 
{
	object_type = ObjectType::DROPPED_ITEM;
	size = { 1, 1 };
}