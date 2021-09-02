#include "Snake.h"

Snake::Snake(int x, int y) :
	tailL(0),
	dir(Direction::STOP)
{
	this->m_Pos.x = x / 2;
	this->m_Pos.y = y / 2;

}

Direction Snake::getSnakeDir()
{
	return this->dir;
}

void Snake::setSnakeDir(Direction userDir)
{
	this->dir = userDir;
}

Position Snake::getPosition()
{
	return this->m_Pos;
}

bool Snake::isRunning()
{
	return this->isAlive;
}

void Snake::incrementPosX()
{
	this->m_Pos.x += 1;
};

void Snake::incrementPosY()
{
	this->m_Pos.y += 1;
};

void Snake::decreasePosX()
{
	this->m_Pos.x -= 1;
};

void Snake::decreasePosY()
{
	this->m_Pos.y -= 1;
};

void Snake::setPosition(Position pos)
{
	this->m_Pos = pos;
};

void Snake::increaseTailLength(int incrStep)
{
	this->tailL += incrStep;
};

int Snake::getTailLength()
{
	return this->tailL;
}

void Snake::setRun(bool alive)
{
	this->isAlive = alive;
};