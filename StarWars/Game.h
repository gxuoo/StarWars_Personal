#pragma once

#include "includes.h"
#include "Object.h"
#include "Character.h"
#include "Particle.h"
#include "DroppedItem.h"
#include "PlayerCharacter.h"
#include "EnemyNPC.h"
#include "Wall.h"

#ifndef GAME_HPP
#define GAME_HPP

class Game {
public:
	Game(bool gameOver);
	bool IsGameOver();
	bool IsStageOver();
	void SetGameOver(bool);
	void SetStageOver(bool);
	void UpdateObjectNextPosition(Object *);
	void UpdateObjectPosition();
	void UpdateObjects();
	void SetBoss(EnemyNPC*);
	EnemyNPC* GetBoss();
	bool IsBossExist();
	bool isOutOfMap(Object * obj);
	std::vector<Object*>& GetObjects();
	const int WIDTH = 41;
	const int HEIGHT = 20;
	static int map[3][20][41];
	static int Curmap[20][41];
private:
	bool gameOver;
	bool stageOver;
	std::vector<Object*> objects;
	EnemyNPC* boss;
};

#endif