#include <iostream>
using namespace std;

int findMaxTrees(int arr[][6], int m, int n)
{

    int prefixSum[m][n] = {0};
    prefixSum[0][0] = arr[0][0];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j > 0)
            {
                prefixSum[0][j] = prefixSum[0][j - 1] + arr[0][j];
            }
            else if (i > 0 and j == 0)
            {
                prefixSum[i][0] = prefixSum[i - 1][0] + arr[i][0];
            }
            else if (i > 0 and j > 0)
            {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + arr[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << prefixSum[i][j] << " ";
        }
        cout << endl;
    }

    // int s1 = prefixSum[x][y];
    // int s2 = prefixSum[x][n - 1] - s1;
    // int s3 = prefixSum[m - 1][y] - s1;
    // int s4 = prefixSum[m - 1][n - 1] - s1 - s2 - s3;

    int maxTrees = 0, x = 0, y = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s1 = prefixSum[i][j];
            int s2 = prefixSum[i][n - 1] - s1;
            int s3 = prefixSum[m - 1][j] - s1;
            int s4 = prefixSum[m - 1][n - 1] - s1 - s2 - s3;

            int minTree = min(s1, min(s2, min(s3, s4)));
            if (maxTrees < minTree)
            {
                maxTrees = minTree;
                x = i;
                y = j;
            }
        }
    }

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "Max: " << maxTrees << endl;

    return -1;
}

int main()
{

    int arr[][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1},
        {1, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0}};

    int m = 6, n = 6;

    findMaxTrees(arr, m, n);

    return 0;
}

/*
https://www.iarcs.org.in/inoi/online-study-material/topics/prefix-sums-ramus-mango-trees.php


Computing Prefix Sums
Two dimension: Ramu's Mango Trees
Ramu's father has left a farm organized as an N × N grid. Each square in the grid either has or does not have a mango tree. He has to divide the farm with his three sisters as follows: he will draw one horizontal line and one vertical line to divide the field into four rectangles. His sisters will choose three of the four smaller fields and he gets the last one.

He wants to divide the field so that he gets the maximum number of mangos possible, assuming that his sisters will pick the best three rectangles.

For example, suppose the field looks as follows:

      . # # . . .
      # . . # # .
      . # . . . .
      . # # . . #
      # . . # # .
      . # . . . .

Ramu can ensure that he gets at least 3 mango trees by cutting as follows:

        . # | # . . .
        # . | . # # .
        . # | . . . .
      ------+---------
        . # | # . . #
        # . | . # # .
        . # | . . . .

Solution

If Ramu draws the vertical line after column x and the horizontal line after row y, we represent it by (x,y). For each cut (x,y), we need to calculate the minimum rectangle that it creates. Then, over all the cuts, we choose the one whose minimum rectangle is maximized.

The problem is to efficiently calculate how a cut divides up the mango trees in the four rectangles.

Let M[x,y] be the number of mango trees in the rectangle between (0,0) and (x,y). We can calculate M[x,y] as follows:

      M[x,y] = 1 + M[x-1,y] + M[x,y-1] - M[x-1,y-1], if tree at (x,y)
             = 0 + M[x-1,y] + M[x,y-1] - M[x-1,y-1], if no tree at (x,y)

Thus, M[x,y] is the number of mango trees in the top left rectangle formed by the cut. Using M[x,y], we can also calculate the number of mango trees in the top right and bottom left rectangles defined by (x,y).

Top right rectangle:

      M[N,y] - M[x,y] : Number of mangos in rectangle defined by (x,y) and (N,0)

Bottom left rectangle:

      M[x,N] - M[x,y] : Number of mangos in rectangle defined by (0,N) and (x,y)

Finally, we subtract these three quantities from total number of mango trees to get number of mangos in fourth rectangle (bottom right), defined by (x,y) and (N,N).
*/