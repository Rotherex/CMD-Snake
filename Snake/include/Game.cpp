#include "Game.h"

Game::Game() :
	mapX(20),
	mapY(20),
	state{
		.map = Map(mapX, mapY),
		.snake = Snake(mapX, mapY),
		.fruit = {},
	}
{

}

void Game::DrawBoard()
{
	Map map = this->state.map;

	int mapSizeX = map.getSizeX();
	int mapSizeY = map.getSizeY();

	this->mapX = mapSizeX;
	this->mapY = mapSizeY;
	
	std::cout << this->mapX;

	system("cls");

	for (int i = 0; i < this->mapX + 2; i++)
	{
		std::cout << "#";
	};

	std::cout << '\n';

	for (int i = 0; i < this->mapY; i++)
	{
		for (int j = 0; j < this->mapX; j++)
		{
			if (j == 0)
			{
				std::cout << "#";
			}

			bool printedSnake = DrawSnake(j, i);

			if (printedSnake) {
				std::cout << 'O';
			}
			else if (DrawFruit(j, i))
			{
				std::cout << 'F';
			}
			else
			{
				bool print = false;

				for (int k = 0; k < state.snake.getTailLength(); k++)
				{
					if (this->tailX[k] == i && this->tailY[k] == j)
					{
						std::cout << "o";
						print = true;
					}
				}

				if (!print)
					std::cout << ' ';
			}

			if (j == this->mapY - 1)
			{
				std::cout << "#";
			}
		}

		std::cout << '\n';
	};

	for (int i = 0; i < this->mapX + 2; i++)
	{
		std::cout << "#";
	};

	std::cout << '\n' << "Score: " << this->score << '\n';
}

bool Game::DrawSnake(int j, int i)
{
	Snake snake = state.snake;

	if (j == snake.getPosition().y && i == snake.getPosition().x)
	{
		return true;
	}

	return false;
}

bool Game::DrawFruit(int j, int i)
{
	for (Fruit* fruit : state.fruit)
	{
		if (j == fruit->getPosition().y && i == fruit->getPosition().x)
		{
			return true;
		}
	}

	return false;
}

Fruit* Game::CreateRandomFruitWithRandomPosition()
{
	int posX = rand() % this->mapX + 1;
	int posY = rand() % this->mapY + 1;

	this->fruitCurrentCount++;

	return dynamic_cast<Fruit*>(new NormalFruit(Position(posX, posY)));
}

void Game::Logic()
{

	int prevX = this->tailX[0];
	int prevY = this->tailY[0];
	int prev2X = 0, prev2Y = 0;
	this->tailX[0] = this->state.snake.getPosition().x;
	this->tailY[0] = this->state.snake.getPosition().y;

	for (int i = 1; i < this->state.snake.getTailLength(); i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (state.snake.getSnakeDir())
	{
	case Direction::LEFT:
		state.snake.decreasePosY();
		break;
	case Direction::RIGHT:
		state.snake.incrementPosY();
		break;
	case Direction::UP:
		state.snake.decreasePosX();
		break;
	case Direction::DOWN:
		state.snake.incrementPosX();
		break;
	default:
		break;
	}

	for (int i = 0; i < this->fruitMaxCount + 1; i++)
	{
		int currentFruits = this->fruitCurrentCount;

		if (currentFruits < this->fruitMaxCount)
		{
		}
	}

	int i = 0;

	for (Fruit* fruit : state.fruit)
	{
		if (fruit->getPosition().x == state.snake.getPosition().x && fruit->getPosition().y == state.snake.getPosition().y)
		{
			fruit->fruitAction(state);
		}
	}

	if (state.snake.getPosition().x >= this->mapX) state.snake.setPosition({ 0 , state.snake.getPosition().y }); else if (state.snake.getPosition().x < 0) state.snake.setPosition({ this->mapX - 1 , state.snake.getPosition().y});
	if (state.snake.getPosition().y >= this->mapY) state.snake.setPosition({ state.snake.getPosition().x , 0 }); else if (state.snake.getPosition().y < 0) state.snake.setPosition({ state.snake.getPosition().x , this->mapY -  1 });

	for (int i = 0; i < state.snake.getTailLength(); i++)
		if (tailX[i] == state.snake.getPosition().x && tailY[i] == state.snake.getPosition().y)
			state.snake.setRun(false);
}

void Game::Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			state.snake.setSnakeDir(Direction::LEFT);
			break;
		case 'd':
			state.snake.setSnakeDir(Direction::RIGHT);
			break;
		case 'w':
			state.snake.setSnakeDir(Direction::UP);
			break;
		case 's':
			state.snake.setSnakeDir(Direction::DOWN);
			break;
		case 'x':
			this->Rescale(15, 15);
			break;
		}
	}
}

void Game::RemoveFruit(Fruit& fruit, int arrayIndex)
{
	delete state.fruit[arrayIndex];

	state.fruit[arrayIndex] = nullptr;

	this->fruitCurrentCount--;
}

void Game::run()
{
	srand(time(NULL));

	while (state.snake.isRunning())
	{
		Game::Input();
		Game::Logic();
		Game::DrawBoard();

		Sleep(100);
	}
}

void Game::Rescale(int x, int y)
{
	this->mapX = x;
	this->mapY = y;

	state.map.setSizeX(x);
	state.map.setSizeY(y);

	int i = 0;

	for (Fruit* fruit : state.fruit)
	{
		if (fruit->getPosition().x >= x || fruit->getPosition().y >= y) {
			this->RemoveFruit(*fruit, i);
		}

		i++;
	}
}

