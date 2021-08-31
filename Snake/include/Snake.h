#pragma once
#include "util.h"
#include <conio.h>

class Snake
{
private:
	Direction dir;

public:
	Snake(int gameSizeX, int gameSizeY);

	Direction getSnakeDir();

	void setSnakeDir(Direction userDir);

	int getPosX();
	int getPosY();

	int getTailLength();

	void setPosX(int posX);
	void setPosY(int posY);

	void incrementPosX();
	void incrementPosY();
	void decreasePosX();
	void decreasePosY();

	void increaseTailLength(int incStep);

	bool isRunning();

private:
	int tailL;

	int snakePosX, snakePosY;

	bool isAlive = true;
};

