#pragma once
class Fruit
{
public:
	Fruit(int posX, int posY);

	void setPosX(int posX);
	void setPosY(int posY);

	int getPosX();
	int getPosY();

private:
	int m_posX, m_posY;
};

