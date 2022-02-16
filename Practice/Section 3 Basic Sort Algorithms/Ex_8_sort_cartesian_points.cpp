#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

void sortCartesian(vector<pair<int, int>> &v)
{
    sort(v.begin(), v.end(), compare);
}

int main()
{
    vector<pair<int, int>> arr = {{3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4}};

    sortCartesian(arr);

    for (pair<int, int> p : arr)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}