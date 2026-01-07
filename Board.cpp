#include "Board.h"
#include <iostream>
#include <time.h>
#include <math.h>

void initializeBoard(Board& board, int size,int size1)
{
    board.size = size;
    board.size1 = size1;
    board.cells = new int* [size];
    for (int i = 0; i < size; i++) {
        board.cells[i] = new int[size1];
    }
}

void setBoard(Board& board, int q)
{
    for (int i = 0; i < board.size; i++) {
        for (int j = 0; j < board.size1; j++) {
            board.cells[i][j] = rand() % q + 1;

        }
    }
}

void displayBoard(Board& board)
{
    const char colors[] = {' ','.',':',';','-','+','=','z','Z','X'};


    for (int i = 0; i < board.size; i++) {
        for (int j = 0; j < board.size1; j++) {
            std::cout << colors[board.cells[i][j]] << " ";

        }
        std::cout << std::endl;
    }
}

void changeStates(Board& board, int q, int k1, int k2, int g)
{
    Board temp_board;
    initializeBoard(temp_board, board.size,board.size1);
    copy(board, temp_board);
    for (int i = 0; i < board.size; i++) {
        for (int j = 0; j < board.size1; j++) {
            if (board.cells[i][j] == q) {
                board.cells[i][j] = 1;
            }
            else if (board.cells[i][j] == 1) {
                int val = valueOne(board, temp_board, i, j, q, k1, k2);
                if (val < q) {
                    board.cells[i][j] = val;
                }
                else
                {
                    board.cells[i][j] = q;
                }

            }
            else if (board.cells[i][j] >= 2 && board.cells[i][j] < q) {
                int val = valueTwo(board, temp_board, i, j, g);
                if (val > q) {

                    board.cells[i][j] = q;
                }
                else
                {
                    board.cells[i][j] = val;
                }
            }
        }
    }
    deleteBoard(temp_board);
}
void copy(Board& b, Board& copy_b)
{
    for (int i = 0; i < b.size; i++) {
        for (int j = 0; j < b.size1; j++) {
            copy_b.cells[i][j] = b.cells[i][j];
        }
    }
    copy_b.size = b.size;
    copy_b.size1 = b.size1;
}

int valueOne(Board& board, Board& copy_board, int a, int b, int q, int k1, int k2)
{
    int c = 0;
    int d = 0;
    for (int i = a - 1; i <= a + 1; i++) {
        for (int j = b - 1; j <= b + 1; j++) {
            if (a == i && b == j) continue;
            if (i < 0 || i >= board.size || j < 0 || j >= board.size1) continue;

            if (copy_board.cells[i][j] >= 2 && copy_board.cells[i][j] < q) {
                c++;
            }
            if (copy_board.cells[i][j] == q) {
                d++;
            }
        }
    }
    return (c / k1) + (d / k2) + 1;
}

int valueTwo(Board& board, Board& copy_board, int a, int b, int g)
{
    int c = 0;
    int  s = 0;
    s += copy_board.cells[a][b];
    for (int i = a - 1; i <= a + 1; i++) {
        for (int j = b - 1; j <= b + 1; j++) {
            if (a == i && b == j) continue;
            if (i < 0 || i >= board.size || j < 0 || j >= board.size1) continue;

            s += copy_board.cells[i][j];
            if (copy_board.cells[i][j] == 1) c++;
        }
    }

    return (s / (9 - c)) + g;
}

void deleteBoard(Board& temp)
{
    for (int i = 0; i < temp.size; i++) {

        delete[] temp.cells[i];
    }
    delete[] temp.cells;
}