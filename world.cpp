#include <iostream>
#include "Life.h"

//������    ����������				����� ������ (������)
//1			0, 1					0  �����������
//1			4, 5, 6, 7, 8			0  �������������
//1			2, 3					1  �����
//0			3						1  ����� �����



int main()
{
	setlocale(LC_ALL, "Russian");

	Life start;
	start.runLife();

	return 0;
}
