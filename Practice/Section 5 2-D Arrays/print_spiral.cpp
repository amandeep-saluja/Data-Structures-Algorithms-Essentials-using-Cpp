#include <iostream>
using namespace std;

void printSpiralMatrix(int arr[][4], int n, int m)
{
    int startRow = 0;
    int endRow = n - 1;
    int startColumn = 0;
    int endColumn = m - 1;

    while (startColumn<=endColumn and startRow<=endRow)
    {
        for (int col = startColumn; col <= endColumn; col++)
        {
            cout << arr[startRow][col] << " ";
        }

        for (int row = startRow + 1; row <= endRow; row++)
        {
            cout << arr[row][endColumn] << " ";
        }

        for (int col = endColumn - 1; col >= startColumn; col--)
        {
            if(startRow==endRow){
                break;
            }
            cout << arr[endRow][col] << " ";
        }

        for (int row = endRow - 1; row >= startColumn + 1; row--)
        {
            if(startColumn==endColumn){
                break;
            }
            cout << arr[row][startColumn] << " ";
        }
        startRow++;
        endColumn--;
        endRow--;
        startColumn++;
    }
}

int main()
{
    int arr[][4] = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}};

    int n = 4, m = 4;

    printSpiralMatrix(arr, n, m);

    return 0;
}