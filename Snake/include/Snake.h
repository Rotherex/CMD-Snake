#pragma once
#include "util.h"
#include <conio.h>
#include "GameState.h"

class Snake
{
private:
	Direction dir;

public:
	Snake(int x, int y);

	Direction getSnakeDir();

	void setSnakeDir(Direction userDir);

	Position getPosition();

	int getTailLength();

	void setPosition(Position pos);

	void incrementPosX();
	void incrementPosY();
	void decreasePosX();
	void decreasePosY();

	void increaseTailLength(int incStep);

	bool isRunning();

	void setRun(bool alive);

private:
	int tailL;

	Position m_Pos;

	bool isAlive = true;
};

