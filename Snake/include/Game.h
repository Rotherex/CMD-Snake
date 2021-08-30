#pragma once
#include "GameState.h"
#include <conio.h>
#include <Windows.h>

class Game
{
public:
	Game(int gameSizeX, int gameSizeY);

	void DrawBoard();

	bool DrawSnake(int j, int i);

	void run();

	void AddFruit(int j, int i);

	void Logic();

	void RemoveFruit();

	void Input();

private:
	int mapX, mapY;

	GameState state;

	Direction snakeDir;
};

