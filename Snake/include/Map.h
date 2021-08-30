#pragma once
#include "Snake.h"
#include <iostream>

class Map
{
public:
	Map(int gameSizeX, int gameSizeY);
	
	int getSizeX();
	int getSizeY();

private:
	int mapSizeX, mapSizeY;
};

