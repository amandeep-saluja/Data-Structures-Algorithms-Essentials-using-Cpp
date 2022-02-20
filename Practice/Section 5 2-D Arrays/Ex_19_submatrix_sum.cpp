#include <iostream>
#include <vector>
using namespace std;

int sum(vector<vector<int>> v, int sr, int sc, int er, int ec)
{
    int m = v.size();
    int n = v[0].size();
    int sum = v[0][0];

    int prefixSum[m][n] = {0};
    prefixSum[0][0] = v[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << v[i][j] << " ";
            if (i == 0 and j > 0)
            {
                prefixSum[0][j] = prefixSum[0][j - 1] + v[0][j];
            }
            else if (i > 0 and j == 0)
            {
                prefixSum[i][0] = prefixSum[i - 1][0] + v[i][0];
            }
            else if (i > 0 and j > 0)
            {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + v[i][j];
            }
        }
    }

    if (sr == 0 and sc > 0)
    {
        sum = prefixSum[er][ec] - prefixSum[er][sc - 1];
    }
    else if (sr > 0 and sc == 0)
    {
        sum = prefixSum[er][ec] - prefixSum[sr - 1][ec];
    }
    else if (sr > 0 and sc > 0)
    {
        sum = prefixSum[er][ec] - prefixSum[sr - 1][ec] - prefixSum[er][sc - 1] + prefixSum[sr - 1][sc - 1];
    }
    else
    {
        sum = prefixSum[er][ec];
    }

    return sum;
}

int main()
{

    vector<vector<int>> mat = {
        {1, 2, 3, 4, 6},
        {5, 3, 8, 1, 2},
        {4, 6, 7, 5, 5},
        {2, 4, 8, 9, 4}};

    // sum(mat, 0, 0, 1, 1);

    cout << "Query 1: " << sum(mat, 0, 0, 1, 1) << endl; // 11

    cout << "Query 2: " << sum(mat, 2, 2, 3, 4) << endl; // 38

    cout << "Query 1: " << sum(mat, 1, 2, 3, 3) << endl; // 38

    return 0;
}

/*

Submatrix Sum

Given a matrix of size M x N, there are large number of queries to find submatrix sums.
Inputs to queries are left top and right bottom indexes of submatrix whose sum is to find out.
How to preprocess the matrix so that submatrix sum queries can be performed in O(1) time.

INPUT FORMAT:
Given a matrix (2d vector) and query.. Each query has Starting row, Starting column, Ending row, Ending column.
OUTPUT FORMAT:A single integer which is the sum of the submatrix.Example :
tli :  Row number of top left of query submatrix
tlj :  Column number of top left of query submatrix
rbi :  Row number of bottom right of query submatrix
rbj :  Column number of bottom right of query submatrix 

Input:

mat[M][N] =
{{1, 2, 3, 4, 6},
{5, 3, 8, 1, 2},
{4, 6, 7, 5, 5},
{2, 4, 8, 9, 4} };

Query1:

tli = 0,
tlj = 0,
rbi = 1,
rbj = 1

Query2:

tli = 2,
tlj = 2,
rbi = 3,
rbj = 4

Query3:

tli = 1,
tlj = 2,
rbi = 3,
rbj = 3; 

Output:

Query1: 11  // Sum between (0, 0) and (1, 1)
Query2: 38  // Sum between (2, 2) and (3, 4)
Query3: 38  // Sum between (1, 2) and (3, 3)

*/