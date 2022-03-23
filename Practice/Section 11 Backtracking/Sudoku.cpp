
#include <iostream>
using namespace std;

void print(int mat[][9], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool validate(int mat[9][9], int n, int i, int j, int num)
{
    // row or column
    for (int k = 0; k < n; k++)
    {
        if (mat[i][k] == num or mat[j][k] == num)
            return false;
    }

    // sub matrix
    int subMatstartI, subMatstartJ, subMatEndI, subMatEndJ;

    if (i >= 0 and i <= 2)
    {
        subMatstartI = 0;
        subMatEndI = 3;
    }
    else if (i >= 3 and i <= 5)
    {
        subMatstartI = 3;
        subMatEndI = 6;
    }
    else
    {
        subMatstartI = 6;
        subMatEndI = 9;
    }

    if (j >= 0 and j <= 2)
    {
        subMatstartJ = 0;
        subMatEndJ = 3;
    }
    else if (j >= 3 and j <= 5)
    {
        subMatstartJ = 3;
        subMatEndJ = 6;
    }
    else
    {
        subMatstartJ = 6;
        subMatEndJ = 9;
    }

    for (int x = subMatstartI; x < subMatEndI; x++)
    {
        for (int y = subMatstartJ; y < subMatEndJ; y++)
        {
            if (mat[x][y] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int mat[9][9], int i, int j, int n)
{
    if (i == n and j == n)
    {
        print(mat, n);
        return true;
    }
    else if (j == n)
    {
        return solveSudoku(mat, i+1, 0, n);
    }

    for (int num = 1; num <= 9; num++)
    {

        if (mat[i][j] != 0)
        {
            if (j > 9)
            {
                i++;
                j = 0;
            }
            else
            {
                j++;
            }
        }
        cout << "i: " << i << " j: " << j << " num: " << num << endl;
        if (validate(mat, n, i, j, num))
        {
            mat[i][j] = num;
            bool success = solveSudoku(mat, i, j + 1, n);

            if (success)
            {
                return true;
            }

            mat[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n = 9;
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!solveSudoku(mat, 0, 0, n))
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}
