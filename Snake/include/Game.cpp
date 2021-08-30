#include "Game.h"

Game::Game(int gameSizeX, int gameSizeY) :
	mapX(gameSizeX),
	mapY(gameSizeY),
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

			bool printed = DrawSnake(j, i);

			if (printed) {
				std::cout << 'O';
			}

			else {

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

	std::cout << std::endl;
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

void Game::AddFruit(int j, int i)
{
	state.fruit.push_back(Fruit(j, i));
}

void Game::Logic()
{

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
		std::cout << "hi";
		break;
	case Direction::DOWN:
		state.snake.incrementPosX();
		break;
	default:
		break;
	}

	for (Fruit fruit : state.fruit)
	{
		if (fruit.getPosX() == state.snake.getPosX() && fruit.getPosY() == state.snake.getPosY())
		{
			RemoveFruit();
		}
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
			std::cout << 'h';
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

void Game::RemoveFruit()
{
	state.fruit.pop_back();
}

void Game::run()
{
	Snake snake = state.snake;

	while (snake.isRunning())
	{
		Game::Input();
		Game::Logic();
		Game::DrawBoard();
		Sleep(50);
	}
}