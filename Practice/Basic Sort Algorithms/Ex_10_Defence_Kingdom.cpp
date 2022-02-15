#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareL(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool compareH(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int defkin(int W, int H, vector<pair<int, int>> position)
{
    int maxLength = 0;
    int maxBreath = 0;
    position.push_back({0, 0});
    position.push_back({W+1, H+1});
    sort(position.begin(), position.end(), compareL);
    for (int i = 0; i < position.size() - 1; i++)
    {
        int len = position[i + 1].first - position[i].first - 1;
        maxLength = max(maxLength, len);
    }
    sort(position.begin(), position.end(), compareH);
    for (int i = 0; i < position.size() - 1; i++)
    {
        int len = position[i + 1].second - position[i].second - 1;
        maxBreath = max(maxBreath, len);
    }

    return maxLength * maxBreath;
}

int main()
{
    vector<pair<int, int>> position = {{3, 8}, {11, 2}, {8, 6}};

    int W = 15, H = 8;

    int penalty = defkin(W, H, position);

    cout << penalty << endl;

    return 0;
}