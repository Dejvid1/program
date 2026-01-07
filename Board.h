#pragma once
struct Board
{
    int size = 0;
    int** cells;
};
void initializeBoard(Board& board, int size);
void setBoard(Board& board, int q);
void displayBoard(Board& board);
void changeStates(Board& board, int q, int k1, int k2, int g);
void copy(Board& b, Board& copy_b);
int valueOne(Board& board, Board& copy_board, int a, int b, int q, int k1, int k2);
int valueTwo(Board& board, Board& copy_board, int a, int b, int g);
void deleteBoard(Board& temp);
