#include "Game.h"

Game::Game(bool gameOver) :gameOver(gameOver)
{
	this->objects = std::vector<Object*>();
}

bool Game::IsGameOver()
{
	return this->gameOver;
}

void Game::SetGameOver(bool gameOver)
{
	this->gameOver = gameOver;
}

std::vector<Object*>& Game::GetObjects()
{
	return this->objects;
}

void Game::UpdateObjectNextPosition(Object* object)
{
	object->SetNextCoord(object->GetCoord() + object->GetVelocity());
}

void Game::UpdateObjects()
{
	auto milli = GetTickCount64();
	bool should_delete = false;

	for (auto& it : objects)
	{
		if (it->last_updated + (1000.0 / it->GetSpeed()) > milli)
			continue;

		if (it->getObjectType() == ObjectType::PLAYER_CHARACTER)
		{
			PlayerCharacter* player = (PlayerCharacter*)(it);

			if (player->getBuffTimer() > 0)
			{
				player->setBuffTimer(player->getBuffTimer() - 1);
			}
			else
			{
				player->isFreeze = false;
				player->SetSpeed(20);
				player->current_buff = 0;
			}

			if (player->isFreeze == true)
			{
				continue;
			}

			if (player->is_mid_air && player->getJumpTimer() < player->getJumpLimit())
				player->GetVelocity().setY(1);

			else if (player->is_mid_air && player->getJumpTimer() >= player->getJumpLimit())
				player->GetVelocity().setY(-1);

			it->last_updated = milli;

		}

		UpdateObjectNextPosition(it);

		if (it == objects[0] || it == objects[1])
		{
			PlayerCharacter* player = (PlayerCharacter*)it;

			player->is_mid_air = true;
		}

		for (int i = 0; i < 2; ++i)
		{
			for (auto& it2 : objects)
			{
				PlayerCharacter* player = (PlayerCharacter*)objects[i];

				if (player->GetVelocity().getY() <= 0 && (it2->getObjectType() == ObjectType::WALL) && (player->GetCoord() + Vec2(0, -1) == it2->GetCoord()))
				{
					player->GetVelocity().setY(0);
					player->is_mid_air = false;

					break;
				}
			}
		}

		for (auto& it2 : objects)
		{
			if (it != it2 && it->IsCollisionWith(it2))
			{
				if (it->IsCharacter() && it2->getObjectType() == ObjectType::WALL)
				{
					if (it->GetNextCoord() == it2->GetCoord())
						it->GetVelocity().setX(0);

					if (it->GetCoord().getY() + 2 == it2->GetCoord().getY())
					{
						PlayerCharacter* player = (PlayerCharacter*)it;

						player->setJumpTimer(player->getJumpLimit());
						it->SetNextCoord(it->GetCoord());
						
						break;
					}

					UpdateObjectNextPosition(it);
				}
				if (it2->IsCharacter() && it->IsItem())
				{
					if (it2 == objects[0])
					{
						((DroppedItem*)it)->useItem(objects[0], objects[1]);
					}
					else
					{
						((DroppedItem*)it)->useItem(objects[1], objects[0]);
					}
					it->SetDeleteObject(true);
					should_delete = true;

					break;
				}

				if (it->getObjectType() == ObjectType::PARTICLE)
				{
					if (it2->getObjectType() == ObjectType::WALL)
					{
						it->SetDeleteObject(true);
						should_delete = true;

						break;
					}

					if (it2->IsCharacter())
					{
						(dynamic_cast<Character*>(it2))->giveDamage((dynamic_cast<Particle*>(it))->getDamage());
						if ((dynamic_cast<Character*>(it2))->getHealth() <= 0)
						{
							this->SetGameOver(true);
						}

						it->SetDeleteObject(true);
						should_delete = true;

						break;
					}
				}
			}
		}

		UpdateObjectPosition();
	}

	if (!should_delete)
		return;

	for (int i = 2; i < objects.size(); ++i)
	{
		if (objects[i]->GetDeleteObject())
		{
			delete (objects[i]);
			objects.erase(objects.begin() + i);

			--i;
		}
	}
}

void Game::UpdateObjectPosition()
{
	PlayerCharacter* player1 = (PlayerCharacter*)objects[0];
	PlayerCharacter* player2 = (PlayerCharacter*)objects[1];

	if (player1->GetCoord() != player1->GetNextCoord())
		player1->setJumpTimer(player1->getJumpTimer() + 1);
	
	if (player2->GetCoord() != player2->GetNextCoord())
		player2->setJumpTimer(player2->getJumpTimer() + 1);

	for (std::vector<Object*>::iterator it = objects.begin(); it < objects.end(); ++it)
		(*it)->SetCoord((*it)->GetNextCoord());
}