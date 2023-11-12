#include "GameManager.h"

GameManager::GameManager()
{
	this->game = new Game(false);
}

void GameManager::MakePlayer()
{
	PlayerCharacter* player1 = new PlayerCharacter();
	PlayerCharacter* player2 = new PlayerCharacter();

	this->game->GetObjects().push_back(player1);
	this->game->GetObjects().push_back(player2);
	
	player1->SetCoord({ 10, 1 });
	player2->SetCoord({ 25, 1 });

	player1->SetNextCoord({ 10, 1 });
	player2->SetNextCoord({ 25, 1 });

	player1->SetVelocity({ -1, 0 });
	player2->SetVelocity({ 1, 0 });

	player1->SetSpeed(20);
	player2->SetSpeed(20);

	for (int i = 0; i < 5; ++i)
	{
		Wall* wall = new Wall();

		wall->SetCoord({ i + 10, 4 });
		wall->SetNextCoord(wall->GetCoord());

		game->GetObjects().push_back(wall);
	}
}

void GameManager::MakeWall()
{
	for (int i = 0; i < game->WIDTH; ++i)
	{
		Wall* w = new Wall();

		w->SetCoord({ i, 0 });
		w->SetNextCoord({ i, 0 });

		Wall* w2 = new Wall();
		w2->SetCoord({ i, game->HEIGHT - 1 });
		w2->SetNextCoord({ i, game->HEIGHT - 1 });

		this->game->GetObjects().push_back(w);
		this->game->GetObjects().push_back(w2);
	}

	for (int i = 1; i < game->HEIGHT - 1; ++i)
	{
		Wall* w = new Wall();

		w->SetCoord({ 0, i });
		w->SetNextCoord({ 0, i });

		Wall* w2 = new Wall();
		w2->SetCoord({ game->WIDTH - 1, i });
		w2->SetNextCoord({ game->WIDTH - 1, i });

		this->game->GetObjects().push_back(w);
		this->game->GetObjects().push_back(w2);
	}
}

void GameManager::StartGame()
{
	this->frameManager.InitFrame();
	
	MakePlayer();
	MakeWall();

	while (PrecedeGame()) 
	{
		this->GetPlayerKeyInput();
		
		this->frameManager.MakeFrame(this->game->GetObjects());
		this->frameManager.UpdateFrame();
	}
}

bool GameManager::PrecedeGame()
{
	if (!this->game->IsGameOver())
	{
		this->game->UpdateObjects();
		return true;
	}

	return false;
}

void GameManager::GetPlayerKeyInput()
{
	PlayerCharacter* player1 = dynamic_cast<PlayerCharacter*>(game->GetObjects()[0]);
	PlayerCharacter* player2 = dynamic_cast<PlayerCharacter*>(game->GetObjects()[1]);

	if (GetAsyncKeyState(0x41))
	{
		player1->GetVelocity().setX(-1);
	}

	if (GetAsyncKeyState(0x44))
	{
		player1->GetVelocity().setX(1);
	}

	else if (!GetAsyncKeyState(0x41) && !GetAsyncKeyState(0x44))
	{
		player1->GetVelocity().setX(0);
	}

	if (GetAsyncKeyState(0x35))
	{
		Particle* p = new Particle();

		p->setDamage(10);

		p->SetCoord(game->GetObjects()[0]->GetCoord() + Vec2{ 1, 0 });
		p->SetNextCoord(game->GetObjects()[0]->GetCoord() + Vec2{ 1, 0 });

		p->SetVelocity(Vec2{ 1, 0 });

		p->SetSpeed(10);

		game->GetObjects().push_back(p);
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		player2->GetVelocity().setX(-1);
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		player2->GetVelocity().setX(1);
	}

	else if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		player2->GetVelocity().setX(0);
	}

	if (GetAsyncKeyState(0x47))
	{
		// p2 shoot
	}

	if (GetAsyncKeyState(0x57))
	{
		if (player1->GetVelocity().getY() == 0)
		{
			player1->setJumpTimer(0);
			player1->GetVelocity().setY(1);
		}
	}

	else if (!GetAsyncKeyState(0x57))
	{
		//player2->setJumpTimer(player2->getJumpTimer() + 2);
	}

	if (GetAsyncKeyState(VK_UP))
	{
		if (player2->GetVelocity().getY() == 0)
		{
			player2->setJumpTimer(0);
			player2->GetVelocity().setY(1);
		}
	}

	else if (!GetAsyncKeyState(VK_UP))
	{
		//player1->setJumpTimer(150);
	}
}