#pragma once
//размер поля
constexpr auto SIZEX = 50;
constexpr auto SIZEY = 50;

class Life
{
	int space[SIZEX][SIZEY];
	int checkLifeAround(int i, int j);
	void generator();
	void outLife();

public:
	Life();
	~Life();
	void runLife();
	int checkWorld();
};

