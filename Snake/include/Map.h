#pragma once
#include "Snake.h"
#include <iostream>

class Map
{
public:
	Map(int gameSizeX, int gameSizeY);
	
	int getSizeX();
	int getSizeY();

	void setSizeX(int X);
	void setSizeY(int Y);

private:
	int mapSizeX, mapSizeY;
};

