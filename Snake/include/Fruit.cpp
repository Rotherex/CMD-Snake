#include "Fruit.h"

Fruit::Fruit(Position pos) :
	m_Pos(pos)
{

}

void Fruit::setPosition(Position newPos)
{
	this->m_Pos = newPos;
}

Position Fruit::getPosition()
{
	return this->m_Pos;
}