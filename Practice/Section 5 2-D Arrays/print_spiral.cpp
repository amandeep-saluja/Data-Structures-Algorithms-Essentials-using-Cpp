#include <iostream>
using namespace std;

void printSpiralMatrix(int arr[][4], int n, int m)
{
    int startRow = 0;
    int endRow = n - 1;
    int startColumn = 0;
    int endColumn = m - 1;

    // if no. of rows are less than no. of columns then stop printing if rows are done.
    while (startColumn<=endColumn and startRow<=endRow)
    {
        // Start Row
        for (int col = startColumn; col <= endColumn; col++)
        {
            cout << arr[startRow][col] << " ";
        }

        // End column
        for (int row = startRow + 1; row <= endRow; row++)
        {
            cout << arr[row][endColumn] << " ";
        }

        // End Row
        for (int col = endColumn - 1; col >= startColumn; col--)
        {
            // Avoids duplicate printint of 
            if(startRow==endRow){
                break;
            }
            cout << arr[endRow][col] << " ";
        }

        // Start Column
        for (int row = endRow - 1; row >= startColumn + 1; row--)
        {
            // Avoids duplicate printing of column elements
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