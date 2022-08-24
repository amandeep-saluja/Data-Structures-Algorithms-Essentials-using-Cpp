#include <bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>> &edges)
{
    int a = edges[0][0], b = edges[0][1];
    int c = edges[1][0], d = edges[1][1];
    if (a == c || a == d)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{

    vector<vector<int>> v = {{1, 2}, {2, 3}, {4, 2}};

    cout << findCenter(v) << endl;

    return 0;
}