#pragma once
#include "GameState.h"

class Fruit
{
public:
	Fruit(Position pos);

	void setPosition(Position newPos);

	Position getPosition();

	virtual void fruitAction(GameState& state) = 0;

protected:
	
	Position m_Pos;
};

