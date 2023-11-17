#include "DroppedSpecialItem.h"

DroppedSpecialItem::DroppedSpecialItem() : DroppedSpecialItem(0)
{

}

DroppedSpecialItem::DroppedSpecialItem(int item_id) : DroppedItem() 
{
	special_item_id = item_id;
	object_type = ObjectType::DROPPED_SPECIAL_ITEM;
}

void DroppedSpecialItem::useItem(Object* itemuser, Object* elseuser, vector< Object*>& objects)
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
	case 3:
		random_device rd;   // non-deterministic generator
		mt19937 gen(rd());  // to seed mersenne twister.
		uniform_int_distribution<> dist(1, 20);

		for (int i = 0; i < 10; i++)
		{
			Particle* p = new Particle();
			p->isBombing = true;

			p->SetSpeed(1);
			p->setDamage(5);
			p->max_range = 50;
			p->SetCoord({ dist(gen), 19});
			p->SetNextCoord(p->GetCoord() + Vec2{ 1, -1 });
			p->SetVelocity(Vec2{ 2, -1 });

			objects.push_back(p);
		}

		for (int i = 0; i < 10; i++)
		{
			Particle* p = new Particle();
			p->isBombing = true;

			p->SetSpeed(1);
			p->setDamage(5);
			p->max_range = 50;
			p->SetCoord({ dist(gen) + 20, 19 });
			p->SetNextCoord(p->GetCoord() + Vec2{ -1, -1 });
			p->SetVelocity(Vec2{ -2, -1 });

			objects.push_back(p);
		}
		break;
	}
}