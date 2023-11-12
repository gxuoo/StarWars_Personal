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

	player1->SetVelocity({ -1, 0 });
	player2->SetVelocity({ 0, -1 });

	while (PrecedeGame()) {
		Sleep(1000);
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
	return;
}