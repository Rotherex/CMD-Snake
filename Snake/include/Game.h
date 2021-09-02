#pragma once
#include "GameState.h"
#include <conio.h>
#include "NormalFruit.h"
#include "SpecialFruit.h"
#include <Windows.h>

class Game
{
public:
	Game();

	void DrawBoard();

	bool DrawSnake(int j, int i);

	void run();

	Fruit* CreateRandomFruitWithRandomPosition();

	bool DrawFruit(int j, int i);

	void Logic();

	void RemoveFruit(Fruit& fruit, int arrayIndex);

	void Input();

	bool DrawTail(int j, int i);

	void Rescale(int x, int y);

private:
	int mapX, mapY;

	GameState state;

	Direction snakeDir;

	int tailX[100], tailY[100];

	int fruitMaxCount = 100;
	int fruitCurrentCount = 0;

	int score = 0;
};

