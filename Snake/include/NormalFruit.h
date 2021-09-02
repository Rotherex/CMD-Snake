#pragma once
#include "Fruit.h"

class NormalFruit : public Fruit
{
public:
	NormalFruit(Position pos);

	virtual void fruitAction(GameState& state) override;
};

