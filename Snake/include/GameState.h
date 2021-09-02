#pragma once
#include "Snake.h"
#include "Map.h"
#include "Fruit.h"
#include <vector>

struct Position {
	int x;
	int y;
};

struct GameState {
	Map map;
	Snake snake;
	std::vector<Fruit*> fruit;
};