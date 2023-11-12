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

	player1->SetSpeed(10);
	player2->SetSpeed(10);
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
	if (GetAsyncKeyState(VK_LEFT))
	{
		PlayerCharacter* player = dynamic_cast<PlayerCharacter*>(game->GetObjects()[0]);
		player->GetVelocity().setX(-1);
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		PlayerCharacter* player = dynamic_cast<PlayerCharacter*>(game->GetObjects()[0]);
		player->GetVelocity().setX(1);
	}

	else if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
	{
		PlayerCharacter* player = dynamic_cast<PlayerCharacter*>(game->GetObjects()[0]);
		player->GetVelocity().setX(0);
	}

	if (GetAsyncKeyState(0x35))
	{
		Particle* p = new Particle();

		p->setDamage(10);

		p->SetCoord(game->GetObjects()[0]->GetCoord() + Vec2{1, 0});
		p->SetNextCoord(game->GetObjects()[0]->GetCoord() + Vec2{ 1, 0 });

		p->SetVelocity(Vec2{ 1, 0 });

		p->SetSpeed(10);
		
		game->GetObjects().push_back(p);
	}

	if (GetAsyncKeyState(0x41))
	{
		PlayerCharacter* player = dynamic_cast<PlayerCharacter*>(game->GetObjects()[1]);
		player->GetVelocity().setX(-1);
	}

	if(GetAsyncKeyState(0x44))
	{
		PlayerCharacter* player = dynamic_cast<PlayerCharacter*>(game->GetObjects()[1]);
		player->GetVelocity().setX(1);
	}

	else if (!GetAsyncKeyState(0x41) && !GetAsyncKeyState(0x44))
	{
		PlayerCharacter* player = dynamic_cast<PlayerCharacter*>(game->GetObjects()[1]);
		player->GetVelocity().setX(0);
	}

	if (GetAsyncKeyState(0x47))
	{
		// p2 shoot
	}

	return;
}