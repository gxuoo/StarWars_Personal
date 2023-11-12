#include "GameManager.h"

GameManager::GameManager()
{
	this->game = new Game(false);
}

void GameManager::StartGame()
{
	this->frameManager.InitFrame();

	PlayerCharacter* player1 = new PlayerCharacter();
	PlayerCharacter* player2 = new PlayerCharacter();
	
	Wall* w = new Wall();

	this->game->GetObjects().push_back(player1);
	this->game->GetObjects().push_back(player2);
	this->game->GetObjects().push_back(w);

	player1->SetCoord({ 10, 1 });
	player2->SetCoord({ 0, 6 });
	w->SetCoord({ 0, 1 });

	/*player1->SetVelocity({ -1, 0 });
	player2->SetVelocity({ 0, -1 });*/

	while (PrecedeGame()) {
		Sleep(1000);
		this->GetPlayerKeyInput(player1, player2);
		
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

void GameManager::GetPlayerKeyInput(PlayerCharacter* player1, PlayerCharacter* player2)
{
	// ÇÃ·¹ÀÌ¾î 1 ¿òÁ÷ÀÓ
	if (GetAsyncKeyState(VK_LEFT))
	{
		player1->SetVelocity({ -1, player1->GetVelocity().getY() });
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		player1->SetVelocity({ 1, player1->GetVelocity().getY() });
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		player1->SetVelocity({ 0, 1 });
	}
	if (GetAsyncKeyState(VK_UP))
	{
		player1->SetVelocity({ 0, -1 });
	}
	if (GetAsyncKeyState(0x35))
	{
		// ÃÑ ½î±â
	}

	// ÇÃ·¹ÀÌ¾î 2 ¿òÁ÷ÀÓ
	if (GetAsyncKeyState(0x41))
	{
		player2->SetVelocity({ -1, player2->GetVelocity().getY() });
	}
	if (GetAsyncKeyState(0x44))
	{
		player2->SetVelocity({ 1, player2->GetVelocity().getY() });
	}
	if (GetAsyncKeyState(0x53))
	{
		player2->SetVelocity({ 0, 1 });
	}
	if (GetAsyncKeyState(0x57))
	{
		player2->SetVelocity({ 0, -1 });
	}
	if (GetAsyncKeyState(0x47))
	{
		// ÃÑ ½î±â
	}
	return;
}