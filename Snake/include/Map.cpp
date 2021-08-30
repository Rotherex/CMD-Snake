#include "Map.h"

Map::Map(int gameSizeX, int gameSizeY)
{
	this->mapSizeX = gameSizeX;
	this->mapSizeY = gameSizeY;
}

int Map::getSizeX()
{
	return this->mapSizeX;
}

int Map::getSizeY()
{
	return this->mapSizeY;
}