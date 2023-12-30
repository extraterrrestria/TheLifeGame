#include <iostream>
#include "Life.h"

//клетка    количество				новая клетка (статус)
//1			0, 1					0  одиночество
//1			4, 5, 6, 7, 8			0  перенаселение
//1			2, 3					1  жизнь
//0			3						1  новая жизнь



int main()
{
	setlocale(LC_ALL, "Russian");

	Life start;
	start.runLife();

	return 0;
}
