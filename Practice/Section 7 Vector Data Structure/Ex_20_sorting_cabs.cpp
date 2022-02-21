#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findDistance(pair<int, int> pt)
{
    return pt.first * pt.first + pt.second * pt.second;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    return findDistance(a) < findDistance(b);
}

vector<pair<int, int>> sortCabs(vector<pair<int, int>> v)
{
    sort(v.begin(), v.end(), compare);
    return v;
}

int main()
{

    vector<pair<int, int>> coordinates = {
        {2, 3},
        {1, 2},
        {3, 4},
        {2, 4},
        {1, 4}};

    coordinates = sortCabs(coordinates);

    for (auto x : coordinates)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}

/*

Sorting Cabs!

Given a vector of pairs representing coordinates x and y of different cabs on a X-Y plane.
Sort them according to their distance from the origin in the non-decreasing order i.e.
the cab with shortest distance from the origin will be at first.

Input Format

In the function an integer vector of pairs is passed.

Output Format

Return an integer vector of pairs in sorted order.

Sample Input

{ (2,3), (1,2), (3,4), (2,4), (1,4) }

Sample Output

{ (1, 2), (2, 3), (1, 4), (2, 4), (3, 4) }

*/