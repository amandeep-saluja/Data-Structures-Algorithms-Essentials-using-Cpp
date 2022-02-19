#include <iostream>
#include <vector>
using namespace std;

vector<int> WavePrint(int m, int n, vector<vector<int>> arr)
{
    vector<int> result;

    int startRow = 0;
    int endRow = m - 1;
    int startColumn = 0;
    int endColumn = n - 1;

    while(endColumn >= startColumn) {
        /*
            endColumn {startRow -> endRow};
            endColumn--;
            endColumn {endRow -> startRow};
            endColumn--;
        */
        for (int row = startRow; row <= endRow; row++) {
            result.push_back(arr[row][endColumn]);
        }
        endColumn--;

        for (int row = endRow; row >= startRow; row--) {
            result.push_back(arr[row][endColumn]);
        }
        endColumn--;
    }

    return result;
}

int main()
{

    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    int m = 4, n = 4;

    vector<int> result = WavePrint(m, n, arr);

    for(int x: result) {
        cout << x << " ";
    }
    cout << endl;

    vector<vector<int>> brr = {
        {1, 9, 4, 10},
        {3, 6, 90, 11},
        {2, 30, 85, 72},
        {6, 31, 99, 15}};

    result = WavePrint(m, n, brr);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}