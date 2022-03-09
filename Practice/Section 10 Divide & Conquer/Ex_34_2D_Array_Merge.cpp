#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(int m, int n, vector<vector<int>> v)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] < v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }
}

vector<vector<int>> mergeSort(int m, int n, vector<vector<int>> v)
{

    if (m >= n)
    {
        return;
    }

    if (n & 1)
    {
        // odd
        int mid = (m + n) / 2;
        mergeSort(m, mid, v);
        mergeSort(mid + 1, n, v);
    }
    else
    {
        // even
        int mid = (m + n) / 2;
        mergeSort(m, mid, v);
        mergeSort(mid + 1, n, v);
    }

    return merge(m, n, v);
}

int main()
{
    vector<vector<int>> matrix = {
        {18, 4, 16, 8},
        {23, 13, 20, 11},
        {28, 24, 26, 25},
        {1, 30, 15, 19}};

    matrix = mergeSort(matrix.size(), matrix[0].size(), matrix);

    for (vector<int> x : matrix)
    {
        for (int y : x)
        {
            cout << y << "\t";
        }
        cout << endl;
    }

    return 0;
}

/*

2D Array Merge

Implement merge sort for a two-dimensional array.
In case of odd dimension, the first division contains more number of elements than the second one.
The complete execution of merge sort arranges the elements in increasing order either moving row-wise or column-wise.

For example, let there be a4×44×4 two dimensional array.
The complete process to be implemented is illustrated in Fig. 1.
Similarly, Fig. 2 demonstrates the scenario for a3×33×3 two dimensional array.
One has to keep on dividing till a single element is remaining.
During merging, first the row elements get sorted in increasing order
followed by sorting of elements lying in the same column.
Fig.1 - 2D Mergesort on a4×44×4 two dimensional array.

*/