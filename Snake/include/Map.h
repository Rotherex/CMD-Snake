#pragma once
#include "Snake.h"
#include <iostream>

class Map
{
public:
	Map(int gameSizeX, int gameSizeY);
	
	int getSizeX();
	int getSizeY();

	int getScore();
	void increaseScore(int scoreStep);

	void setSizeX(int X);
	void setSizeY(int Y);

private:
	int mapSizeX, mapSizeY;

	int score;
};

