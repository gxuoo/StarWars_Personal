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

	player1->setWeapon(1);
	player2->setWeapon(2);
}

void GameManager::MakeItem()
{
	DroppedWeapon* weapon1 = new DroppedWeapon(4);
	DroppedWeapon* weapon2 = new DroppedWeapon(5);
	DroppedWeapon* weapon3 = new DroppedWeapon(3);

	DroppedSpecialItem* item1 = new DroppedSpecialItem(2);
	DroppedSpecialItem* item2 = new DroppedSpecialItem(1);
	DroppedSpecialItem* item3 = new DroppedSpecialItem(3);

	((Object*)weapon1)->SetCoord({ 15, 1 });
	((Object*)weapon2)->SetCoord({ 10, 4 });
	((Object*)weapon3)->SetCoord({10, 10 });
	((Object*)weapon1)->SetNextCoord({ 15, 1 });
	((Object*)weapon2)->SetNextCoord({ 10, 5 });
	((Object*)weapon3)->SetNextCoord({ 20, 10 });
	((Object*)item1)->SetCoord({ 23, 4 });
	((Object*)item1)->SetNextCoord({ 23, 4 });
	((Object*)item2)->SetCoord({ 25, 8 });
	((Object*)item2)->SetNextCoord({ 25, 8 });
	((Object*)item3)->SetCoord({ 28, 1 });
	((Object*)item3)->SetNextCoord({ 28, 1 });

	this->game->GetObjects().push_back(((Object*)weapon1));
	this->game->GetObjects().push_back(((Object*)weapon2));
	this->game->GetObjects().push_back(((Object*)weapon3));
	this->game->GetObjects().push_back(((Object*)item1));
	this->game->GetObjects().push_back(((Object*)item2));
	this->game->GetObjects().push_back(((Object*)item3));
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

void GameManager::MakeMap()
{
	for (int y = 1; y < game->HEIGHT - 1; ++y)
	{
		for (int x = 1; x < game->WIDTH - 1; ++x)
		{
			if (Game::map[game->HEIGHT - y - 1][x ] == 1)
			{
				Wall* wall = new Wall();

				wall->SetCoord({ x, y });
				wall->SetNextCoord(wall->GetCoord());

				game->GetObjects().push_back(wall);
			}
		}
	}
}

void GameManager::StartGame()
{
	this->frameManager.InitFrame();
	
	MakePlayer();
	MakeWall();
	MakeItem();
	MakeMap();
	while (PrecedeGame()) 
	{
		this->GetPlayerKeyInput();
		


		this->frameManager.MakeFrame(this->game->GetObjects());
		this->frameManager.UpdateFrame();
	}

	Sleep(100);
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
		player1->direction = -1;
	}

	if (GetAsyncKeyState(0x44))
	{
		player1->GetVelocity().setX(1);
		player1->direction = 1;
	}

	else if (!GetAsyncKeyState(0x41) && !GetAsyncKeyState(0x44))
		player1->GetVelocity().setX(0);

	if (GetAsyncKeyState(0x47))
		PlayerShoot(player1);

	if (GetAsyncKeyState(VK_LEFT))
	{
		player2->GetVelocity().setX(-1);
		player2->direction = -1;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		player2->GetVelocity().setX(1);
		player2->direction = 1;
	}

	else if (!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT))
		player2->GetVelocity().setX(0);

	if (GetAsyncKeyState(VK_NUMPAD5))
		PlayerShoot(player2);

	if (GetAsyncKeyState(0x57))
	{
		if (player1->GetVelocity().getY() == 0)
		{
			player1->setJumpTimer(0);
			player1->GetVelocity().setY(1);
		}
	}

	if (GetAsyncKeyState(VK_UP))
	{
		if (player2->GetVelocity().getY() == 0)
		{
			player2->setJumpTimer(0);
			player2->GetVelocity().setY(1);
		}
	}
}

void GameManager::PlayerShoot(PlayerCharacter* player)
{
	auto milli = GetTickCount64();

	if (player->last_shot + (1000.0 / player->getWeaponRPM()) > milli)
		return;

	if(player->bullet_count != 0)
		player->bullet_count -= 1;
	player->last_shot = milli;

	for (int i = 0; i < (player->isWeaponShotgun() ? 3 : 1); i++)
	{
		Particle* p = new Particle();

		p->SetSpeed(player->getWeaponSpeed());
		p->setDamage(player->getWeaponDamage());
		p->shooter = player;
		p->max_range = player->getWeaponMaxRange();
		p->isMelee = player->isWeaponMelee();
		p->isShotgun = player->isWeaponShotgun();

		if (player->direction >= 0)
		{
			p->SetCoord(player->GetCoord() + Vec2{ 1, i });
			p->SetNextCoord(player->GetCoord() + Vec2{ 1, i });
			p->SetVelocity(Vec2{ 1, 0 });
		}

		else
		{
			p->SetCoord(player->GetCoord() + Vec2{ -1, i });
			p->SetNextCoord(player->GetCoord() + Vec2{ -1, i });
			p->SetVelocity(Vec2{ -1, 0 });
		}

		

		game->GetObjects().push_back(p);
	}

	if (player->bullet_count == 0)
	{
		player->setWeapon(0);
	}

	
}


