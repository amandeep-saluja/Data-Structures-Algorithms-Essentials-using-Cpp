#include <iostream>
using namespace std;

void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlace(int board[][20], int n, int x, int y)
{
    // column
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
        }
    }
    // Left Diag
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    // Right Diag
    i = x;
    j = y;
    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

bool solveNQueens(int n, int board[][20], int i)
{
    // base case
    if (i == n)
    {
        // Print the board
        printBoard(n, board);
        return true;
    }

    // recursive case
    // try to place a queen in every row
    for (int j = 0; j < n; j++)
    {
        // whether the current i, j is safe or not
        if (canPlace(board, n, i, j))
        {
            board[i][j] = 1;
            bool sucess = solveNQueens(n, board, i + 1);
            if (sucess)
            {
                return true;
            }
            // backtrack
            board[i][j] = 0;
        }
    }
    // if every position in row is wrong/ not safe then return false to parent
    return false;
}

int main()
{
    int board[20][20] = {0};
    int n;
    cin >> n;

    solveNQueens(n, board, 0);

    return 0;
}

/*

N-Queen Problem

N-Queen is a problem of placing N chess Queen on an NxN chessboard
so that no two queens attack each other.

Input:
N = 4

Output:
2D Matrix with Queens

*/