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

void Map::setSizeX(int X)
{
	this->mapSizeX = X;
};

void Map::setSizeY(int Y)
{
	this->mapSizeY = Y;
};

int Map::getScore()
{
	return this->score;
}

void Map::increaseScore(int scoreStep)
{
	this->score += scoreStep;
}