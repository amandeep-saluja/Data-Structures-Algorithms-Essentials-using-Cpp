#include <iostream>
#include <vector>
using namespace std;
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1

vector<vector<int>> printPascal(int n)
{
    vector<vector<int>> arr;
    arr.push_back({1});
    arr.push_back({1, 1});

    for (int i = 2, j = 1; i < n; i++)
    {
        vector<int> brr;
        brr.push_back(1);

        for (j = 1; j < i; j++)
        {
            brr.push_back(arr[i - 1][j - 1] + arr[i - 1][j]);
        }

        brr.push_back(1);
        arr.push_back(brr);
    }

    return arr;
}

int main()
{
    int n = 5;
    vector<vector<int>> arr = printPascal(n);

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