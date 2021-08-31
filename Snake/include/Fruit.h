#pragma once
class Fruit
{
public:
	Fruit(int posX, int posY, int pointsIncrement, int tailStep);

	void setPosX(int posX);
	void setPosY(int posY);

	int getPosX();
	int getPosY();

	int getPointIncr();
	int getTailStep();

private:
	int m_posX, m_posY;

	int pointsIncrement;

	int tailStep;
};

