#include <iostream>
using namespace std;

pair<int, int> stareCaseSearch(int arr[][4], int n, int m, int key)
{
    int startRow = 0;
    int endRow = n - 1;
    int startColumn = 0;
    int endColumn = m - 1;

    pair<int, int> result = {-1, -1};
    int row, col;

    int diff1 = abs(arr[startRow][endColumn] - key);
    int diff2 = abs(arr[endRow][startColumn] - key);
    cout << "D1: " << diff1 << " D2: " << diff2 << endl;
    if (diff1 < diff2)
    {
        row = startRow;
        col = endColumn;

        while (row <= endRow and col >= startColumn)
        {
            // cout << "Row: " << row << " Col: " << col << " -> ";
            cout << arr[row][col] << " -> ";
            if (arr[row][col] == key)
            {
                result.first = row;
                result.second = col;
                break;
            }
            else if (arr[row][col] < key)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
    }
    else
    {
        row = endRow;
        col = startColumn;

        while (row >= startRow and col <= endColumn)
        {
            // cout << "Row: " << row << " Col: " << col << " -> ";
            cout << arr[row][col] << " -> ";
            if (arr[row][col] == key)
            {
                result.first = row;
                result.second = col;
                break;
            }
            else if (arr[row][col] < key)
            {
                col++;
            }
            else
            {
                row--;
            }
        }
    }

    return result;
}

int main()
{
    int arr[][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}};

    int n = 4, m = 4, key = 26;

    pair<int, int> index = stareCaseSearch(arr, n, m, key);

    if (index.first != -1)
    {
        cout << "Element found " << arr[index.first][index.second] << " at index: " << index.first << " , " << index.second << endl;
    }
    else
    {
        cout << "Not found";
    }

    return 0;
}