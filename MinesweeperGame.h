#pragma once
#include "Game.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class MinesweeperGame : public Game
{
private:
    static const int SIZE = 5;
    static const int MINES = 5;

    char board[SIZE][SIZE];     
    char display[SIZE][SIZE];    
    bool revealed[SIZE][SIZE];

public:
    MinesweeperGame() : Game("Minesweeper")
    {
        initialize();
    }

    void initialize()
    {
        
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                board[i][j] = '0';
                display[i][j] = '*';
                revealed[i][j] = false;
            }
        }

        
        int placed = 0;
        while (placed < MINES)
        {
            int r = rand() % SIZE;
            int c = rand() % SIZE;

            if (board[r][c] != 'M'){
                board[r][c] = 'M';
                placed++;
            }
        }

        
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == 'M') 
                    continue;

                int count = 0;

                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        int ni = i + x;
                        int nj = j + y;

                        if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE)
                        {
                            if (board[ni][nj] == 'M')
                                count++;
                        }
                    }
                }

                board[i][j] = count + '0';
            }
        }
    }

    void printBoard()
    {
        cout << "\n   ";
        for (int i = 0; i < SIZE; i++)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << "  ";
            for (int j = 0; j < SIZE; j++)
            {
                cout << display[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool reveal(int r, int c)
    {
        if (r < 0 || r >= SIZE || c < 0 || c >= SIZE)
            return true;

        if (revealed[r][c])
            return true;

        revealed[r][c] = true;

        if (board[r][c] == 'M')
        {
            display[r][c] = 'M';
            return false; 
        }

        display[r][c] = board[r][c];

        
        if (board[r][c] == '0')
        {
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    reveal(r + x, c + y);
                }
            }
        }

        return true;
    }

    bool checkWin()
    {
        int safeCells = SIZE * SIZE - MINES;
        int revealedCount = 0;

        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (revealed[i][j] && board[i][j] != 'M')
                    revealedCount++;

        return revealedCount == safeCells;
    }

    void play() override
    {
        int r, c;
        cout << "\n ------------------ Welcome to Minesweeper! --------------------\n";
        while (true)
        {
            printBoard();
            cout << "Enter row and column: ";
            cin >> r >> c;

            if (!reveal(r, c))
            {
                cout << "BOOM! You hit a mine!\n";
                break;
            }

            if (checkWin())
            {
                cout << "You won the game!\n";
                break;
            }
        }
    }
};
