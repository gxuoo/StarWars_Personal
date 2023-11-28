#pragma once

#include "Frame.h"
#include "Object.h"
#include "PlayerCharacter.h"
#include "EnemyNPC.h"

#ifndef FRAME_MANAGER_HPP
#define FRAME_MANAGER_HPP

class FrameManager {
public:
	void InitFrame();
	void DestroyFrame();
	void ClearScreen();
	void SwapBuffer();
	void Print(const char*);
	void PrintWithPosition(const char*, COORD);
	void UpdateFrame();
	void ClearBuffer();
	void SetCursorPosition(COORD);
	COORD GetCursorPosition();
	void MakeFrame(std::vector<Object*>&);
	void drawStatus(PlayerCharacter* player1, PlayerCharacter* player2);
private:
	Frame frame;
};

#endif
