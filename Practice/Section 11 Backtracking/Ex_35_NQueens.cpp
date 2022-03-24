#include <bits/stdc++.h>
using namespace std;

bool validate(int arr[][20], int n, int i, int j)
{
    // vertical
    for (int k = i; k >= 0; k--)
    {
        if (arr[k][j] == 1)
            return false;
    }

    int k = i;
    int l = j;
    // left diagonal
    while (k >= 0 and l >= 0)
    {
        if (arr[k][l] == 1)
            return false;
        k--;
        l--;
    }

    // right diagonal
    k = i;
    l = j;
    while (k >= 0 and l < n)
    {
        if (arr[k][l] == 1)
            return false;
        k--;
        l++;
    }

    return true;
}

int solveNQueen(int arr[][20], int n, int i)
{
    // base case
    if (i == n)
    {
        // print(arr, n);
        return 1;
    }

    // recursive case
    int ways = 0;

    for (int j = 0; j < n; j++)
    {
        if (validate(arr, n, i, j))
        {
            arr[i][j] = 1;
            ways += solveNQueen(arr, n, i + 1);
            // backtrack
            arr[i][j] = 0;
        }
    }
    return ways;
}

int nQueen(int n)
{
    int arr[20][20] = {0};
    return solveNQueen(arr, n, 0);
}

int main()
{

    cout << nQueen(8) << endl;

    return 0;
}