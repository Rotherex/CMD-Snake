#include "NormalFruit.h"

void NormalFruit::fruitAction(GameState& state) override
{

		state.snake.increaseTailLength(1);
		state.map.increaseScore(1);
};