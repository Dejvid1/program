#include <iostream>
#include <time.h>
#include <math.h>
#include "Board.h"
#include <windows.h>
int main()
{
    srand(time(NULL));
    Board b;
    int q = 9;
    int g = 3;
    int k1 = 2;
    int k2 = 3;
 
    initializeBoard(b, 30);
    setBoard(b, q);
    for (int i = 0; i < 10; i++)
    {
        changeStates(b, q, k1, k2, g);
        //displayBoard(b);
       // Sleep(2000);
        //system("cls");
    }
    displayBoard(b);
    deleteBoard(b);
}

