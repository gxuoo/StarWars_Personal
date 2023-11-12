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

void Game::UpdateObjectNextPosition(Object *object)
{
	object->SetNextCoord(object->GetCoord() + object->GetVelocity());
}

void Game::UpdateObjects()
{
	auto milli = GetTickCount64();
	bool should_delete = false;

	for (auto& it: objects)
	{
		if (it->lastupdated + (1000 / it->GetSpeed()) > milli)
			continue;

		it->lastupdated = milli;
		UpdateObjectNextPosition(it);

		for (auto& it2 : objects)
		{
			if (it != it2 && it->IsCollisionWith(it2))
			{
				if (it->IsCharacter() && it2->getObjectType() == ObjectType::WALL)
				{
					it->SetNextCoord(it->GetCoord());
				}

				if (it2->IsCharacter() && it->IsItem())
				{
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
						it->SetDeleteObject(true);
						should_delete = true;

						break;
					}
				}
			}
		}

		this->UpdateObjectPosition();

		if (it == objects[0])
			objects[0]->GetVelocity().setX(0);

		if (it == objects[1])
			objects[1]->GetVelocity().setX(0);
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
	for (std::vector<Object*>::iterator it = objects.begin(); it < objects.end(); ++it)
		(*it)->SetCoord((*it)->GetNextCoord());
}