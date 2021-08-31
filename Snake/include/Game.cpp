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

	std::cout << std::endl << "Score: " << this->score << std::endl;
}

bool Game::DrawSnake(int j, int i)
{
	Snake snake = state.snake;

	if (j == snake.getPosY() && i == snake.getPosX())
	{
		return true;
	}

	return false;
}

bool Game::DrawFruit(int j, int i)
{
	for (Fruit fruit : state.fruit)
	{
		if (j == fruit.getPosY() && i == fruit.getPosX())
		{
			return true;
		}
	}

	return false;
}

void Game::AddFruit()
{
	int posX = rand() % this->mapX + 1;
	int posY = rand() % this->mapY + 1;

	int increment = rand() % 5 + 1;

	state.fruit.push_back(Fruit(posX, posY, increment, 1));
	this->fruitCurrentCount++;
}

void Game::Logic()
{

	int prevX = this->tailX[0];
	int prevY = this->tailY[0];
	int prev2X = 0, prev2Y = 0;
	this->tailX[0] = this->state.snake.getPosX();
	this->tailY[0] = this->state.snake.getPosY();

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
			this->AddFruit();
		}
	}

	int i = 0;

	for (Fruit fruit : state.fruit)
	{
		if (fruit.getPosX() == state.snake.getPosX() && fruit.getPosY() == state.snake.getPosY())
		{
			RemoveFruit(fruit, i);
		}

		i++;
	}

	if (state.snake.getPosX() >= this->mapX) state.snake.setPosX(0); else if (state.snake.getPosX() < 0) state.snake.setPosX(this->mapX - 1);
	if (state.snake.getPosY() >= this->mapY) state.snake.setPosY(0); else if (state.snake.getPosY() < 0) state.snake.setPosY(this->mapY - 1);
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
			break;
		}
	}
}

void Game::RemoveFruit(Fruit& fruit, int arrayIndex)
{
	state.fruit.erase(state.fruit.begin() + arrayIndex);

	this->score += fruit.getPointIncr();

	state.snake.increaseTailLength(fruit.getTailStep());

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
		Sleep(50);
	}
}