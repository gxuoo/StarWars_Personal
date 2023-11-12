#include "Game.h"
#include "Character.h"
#include "Particle.h"
#include "DroppedItem.h"

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

void Game::UpdateObjects()
{
	for (std::vector<Object*>::iterator it = objects.begin(); it < objects.end(); ++it)
	{
		if((*it)->IsCharacter() && (*it)->GetVelocity().getY() < 0)
		{
			if(((Character*)(*it))->getJumpTimer() < ((Character*)(*it))->getJumpLimit()) 
			{
				((Character*)(*it))->setJumpTimer(((Character*)(*it))->getJumpTimer() + 1);
			}
			else
			{
				((Character*)(*it))->setJumpTimer(0);
				(*it)->SetVelocity({ (*it)->GetVelocity().getX(), 1 });
			}
		}

		(*it)->SetNextCoord((*it)->GetCoord() + (*it)->GetVelocity());
	}

	for (std::vector<Object *>::iterator it = objects.begin(); it < objects.end(); ++it)
	{
		bool isCharacterFalling = true;
		if (!(*it)->IsCharacter() || (*it)->GetVelocity().getY() < 0)
		{
			isCharacterFalling = false;
		}

		
		for (std::vector<Object*>::iterator it2 = objects.begin(); it2 < objects.end(); ++it2)
		{
			if (it != it2 && (*it)->IsCollisionWith(*(*it2)))
			{
				if ((*it)->IsCharacter() && (*it2)->getObjectType() == ObjectType::WALL)
				{
					(*it)->SetNextCoord((*it)->GetCoord());
				}

				if ((*it)->getObjectType() == ObjectType::PARTICLE)
				{
					if ((*it2)->IsCharacter())
					{
						((Character*)(*it2))->giveDamage(((Particle*)(*it))->getDamage());
						(*it)->SetDeleteObject(true);

						break;
					}

					if ((*it2)->getObjectType() == ObjectType::WALL)
					{
						(*it)->SetDeleteObject(true);

						break;
					}
				}

				if ((*it2)->IsCharacter() && (*it)->IsItem())
				{
					(*it)->SetDeleteObject(true);

					break;
				}
			}
			
			if (isCharacterFalling == true && (*it2)->getObjectType() == ObjectType::WALL && (*it)->GetNextCoord() + Vec2(0, 1) == (*it2)->GetNextCoord())
			{
				isCharacterFalling = false;
				(*it)->SetVelocity({ (*it)->GetVelocity().getX(), 0 });
			}

		}
		if (isCharacterFalling)
		{
			(*it)->SetVelocity({ (*it)->GetVelocity().getX(), 1 });
		}
	}

	for (int i = 0; i < objects.size(); ++i)
	{
		if (objects[i]->GetDeleteObject())
		{
			delete (objects[i]);
			objects.erase(objects.begin() + i);
			--i;
		}
	}

	this->UpdateObjectPosition();
}

void Game::UpdateObjectPosition()
{
	for (std::vector<Object*>::iterator it = objects.begin(); it < objects.end(); ++it)
		(*it)->SetCoord((*it)->GetNextCoord());

	//objects[0]->GetSpeed().setX(0);
	//objects[1]->GetSpeed().setX(0);
}