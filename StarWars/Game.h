#pragma once

#include "includes.h"
#include "Object.h"

#ifndef GAME_HPP
#define GAME_HPP

class Game {
public:
	Game(bool gameOver);
	bool IsGameOver();
	void SetGameOver(bool);
	void UpdateObjectNextPosition();
	void UpdateObjectPosition();
	void UpdateObjects();
	std::vector<Object*>& GetObjects();
private:
	bool gameOver;
	std::vector<Object*> objects;
	int current_step;
};

#endif