#include "FrameManager.h"
#include <string>

void FrameManager::InitFrame()
{
	this->frame.consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	this->frame.currentBufferIndex = 0;

	CONSOLE_CURSOR_INFO consoleCursor{ 1, FALSE };
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo{ 0, };
	GetConsoleScreenBufferInfo(this->frame.consoleHandler, &consoleInfo);
	consoleInfo.dwSize.X = 40;
	consoleInfo.dwSize.Y = 30;

	this->frame.consoleInfo.nWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
	this->frame.consoleInfo.nHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top;

	this->frame.bufferHandler[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(this->frame.bufferHandler[0], consoleInfo.dwSize);
	SetConsoleWindowInfo(this->frame.bufferHandler[0], TRUE, &consoleInfo.srWindow);
	SetConsoleCursorInfo(this->frame.bufferHandler[0], &consoleCursor);

	this->frame.bufferHandler[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(this->frame.bufferHandler[1], consoleInfo.dwSize);
	SetConsoleWindowInfo(this->frame.bufferHandler[1], TRUE, &consoleInfo.srWindow);
	SetConsoleCursorInfo(this->frame.bufferHandler[1], &consoleCursor);
}

void FrameManager::DestroyFrame()
{
	if (this->frame.bufferHandler[0] != nullptr)
	{
		CloseHandle(this->frame.bufferHandler[0]);
	}

	if (this->frame.bufferHandler[1] != nullptr)
	{
		CloseHandle(this->frame.bufferHandler[1]);
	}
}

void FrameManager::UpdateFrame()
{
	this->ClearScreen();
	this->SwapBuffer();
	this->ClearBuffer();
}

void FrameManager::ClearScreen()
{
	COORD pos = { 0, 0 };
	DWORD dwWritten = 0;
	unsigned int size = this->frame.consoleInfo.nWidth * this->frame.consoleInfo.nHeight;

	FillConsoleOutputCharacter(this->frame.consoleHandler, ' ', size, pos, &dwWritten);
}

void FrameManager::SwapBuffer()
{
	SetConsoleActiveScreenBuffer(this->frame.bufferHandler[this->frame.currentBufferIndex]);
	this->frame.currentBufferIndex = this->frame.currentBufferIndex ? 0 : 1;
}

void FrameManager::Print(const char* str)
{
	COORD coord = GetCursorPosition();

	PrintWithPosition(str, coord);
}

void FrameManager::PrintWithPosition(const char* str, COORD coord)
{
	int len = strlen(str);
	this->SetCursorPosition(coord);
	WriteFile(this->frame.bufferHandler[this->frame.currentBufferIndex], str, len, nullptr, NULL);
}

void FrameManager::ClearBuffer()
{
	const int WIDTH = this->frame.consoleInfo.nWidth;
	const int HEIGHT = this->frame.consoleInfo.nHeight;

	char* line = (char*)malloc(sizeof(char) * (WIDTH + 1));
	for (int i = 0; i < WIDTH; ++i)
		line[i] = ' ';

	for (short i = 0; i < HEIGHT; ++i)
	{
		this->SetCursorPosition({ 0, i });
		WriteFile(this->frame.bufferHandler[this->frame.currentBufferIndex], line, WIDTH, nullptr, NULL);
	}
}

void FrameManager::SetCursorPosition(COORD coord)
{
	SetConsoleCursorPosition(this->frame.bufferHandler[this->frame.currentBufferIndex], coord);
}

COORD FrameManager::GetCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleBufferInfo;
	GetConsoleScreenBufferInfo(this->frame.bufferHandler[this->frame.currentBufferIndex], &consoleBufferInfo);

	return { consoleBufferInfo.dwCursorPosition.X, consoleBufferInfo.dwCursorPosition.Y };
}

void FrameManager::MakeFrame(std::vector<Object*>& objects)
{
	SetCursorPosition({ (short)((objects[0])->GetCoord().getX() * 2), (short)(20 - (objects[0])->GetCoord().getY()) });
	SetConsoleTextAttribute(this->frame.bufferHandler[this->frame.currentBufferIndex], 12);
	Print("бр");

	SetCursorPosition({ (short)((objects[0])->GetCoord().getX() * 2), (short)(20 - (objects[0])->GetCoord().getY() - 1) });
	Print("бр");

	SetCursorPosition({ (short)((objects[1])->GetCoord().getX() * 2), (short)(20 - (objects[1])->GetCoord().getY()) });
	SetConsoleTextAttribute(this->frame.bufferHandler[this->frame.currentBufferIndex], 14);
	Print("бр");

	SetCursorPosition({ (short)((objects[1])->GetCoord().getX() * 2), (short)(20 - (objects[1])->GetCoord().getY() - 1) });
	Print("бр");

	SetConsoleTextAttribute(this->frame.bufferHandler[this->frame.currentBufferIndex], 15);

	for (std::vector<Object*>::iterator it = objects.begin() + 2; it != objects.end(); ++it)
	{
		SetCursorPosition({ (short)((*it)->GetCoord().getX() * 2), (short)(20 - (*it)->GetCoord().getY()) });
		
		switch ((*it)->getObjectType())
		{
		case ObjectType::WALL:
			Print("б█");
			break;
		default:
			Print("бс");
		}
	}

	SetCursorPosition({ 10, 10 });
	std::string str = std::to_string(((PlayerCharacter*)objects[0])->GetVelocity().getX()) + " " + std::to_string(((PlayerCharacter*)objects[0])->GetVelocity().getY());
	Print(str.c_str());
}