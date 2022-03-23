
#include <iostream>
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

void print(int arr[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
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

int main()
{
    int n;
    cin >> n;
    int arr[20][20] = {0};

    cout << "No of ways: " << solveNQueen(arr, n, 0) << endl;

    return 0;
}
