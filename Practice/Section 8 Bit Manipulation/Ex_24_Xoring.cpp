#include <bits/stdc++.h>
using namespace std;

int xoring(vector<int> v)
{
    int n = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        n = n ^ v[i];
    }

    return n;
}

int main()
{

    vector<int> arr = {1, 2, 3, 1, 4, 2, 3};

    int n = xoring(arr);

    cout << n << endl;

    return 0;
}