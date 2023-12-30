#include "Life.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>

Life::Life() { // конструктор
    for (int i = 0; i < SIZEY + 2; i++) {
        for (int j = 0; j < SIZEX + 2; j++) {
            space[i][j] = 0;
        }
    }
}

Life::~Life() { // деструктор

}


int Life::checkLifeAround(int i, int j)
{
    int alive = 0;                                       // - - -
    for (int n = i - 1; n < i + 2; n++) {                // - * -  8 соседей смотрим
        for (int m = j - 1; m < j + 2; m++) {            // - - - 
            alive += space[n][m];
        }
    }
    alive -= space[i][j]; // посчитали саму *, теперь вычитаем

    if (alive == 3 && space[i][j] == 0)
        space[i][j] = 1;
    if ((alive < 2 || alive > 3) && space[i][j] == 1)
        space[i][j] = 0; // клетка умерла от плохих условий :(


    return 0;
}

void Life::outLife()
{
    for (int i = 0; i < SIZEY + 1; i++) {
        for (int j = 0; j < SIZEX + 1; j++) {
            if (space[i][j] == 1) {
                std::cout << '*';
            }
            else {
                std::cout << '-';
            }
        }
        std::cout << std::endl;
    }
}

void Life::generator()
{
    srand(time(0));
    for (int i = 0; i < SIZEY + 1; i++) {
        for (int j = 0; j < SIZEX + 1; j++) {
            space[i][j] = rand() % 2;
        }
    }
}

void Life::runLife()
{
    generator();
    outLife();
    Sleep(2000); // задержка 2 секунды
    system("cls"); // очистка поля
    bool toggle = 1;
    while (toggle) {
        int life = checkWorld();
        for (int i = 0; i < SIZEY + 1; i++) {
            for (int j = 0; j < SIZEX + 1; j++) {
                checkLifeAround(i, j);
            }
        }
        outLife();
        Sleep(3000);
        system("cls");
        if (life == 0)
            toggle = 0;
    }
}

int Life::checkWorld()
{
    int life = 0;
    for (int i = 0; i < SIZEY + 1; i++) {
        for (int j = 0; j < SIZEX + 1; j++) {
            life += space[i][j];
        }
    }

    return life;
}
