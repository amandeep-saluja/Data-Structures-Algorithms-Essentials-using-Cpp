#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> makeZeroes(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<pair<int, int>> zeros;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
                zeros.push_back({i, j});
        }
    }

    for (int i = 0; i < zeros.size(); i++)
    {
        // cout<<zeros[i].first<<" "<<zeros[i].second<<endl;
        int row = zeros[i].first;
        int col = zeros[i].second;
        for (int i = 0; i < m; i++)
        {
            matrix[row][i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            matrix[i][col] = 0;
        }
    }

    return matrix;
}

int main()
{

    // vector<vector<int>> arr = {{5, 4, 3, 9},
    //                          {2, 0, 7, 6},
    //                          {1, 3, 4, 0},
    //                          {9, 8, 3, 4}};

    vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    for (vector<int> x : arr)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    cout << endl;

    arr = makeZeroes(arr);

    for (vector<int> x : arr)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

Make Zeroes

Given a two-dimensional array, if any element within is zero, make its whole row and column zero.
For example, consider the matrix below.

Input Format

In the function a 2d vector is passed.

Output Format

Return the updated 2d vector.

Sample Input

{ {5, 4, 3, 9}, {2, 0, 7, 6}, {1, 3, 4, 0}, {9, 8, 3, 4} }

Sample Output

{ {5, 0, 3, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {9, 0, 3, 0} }

*/