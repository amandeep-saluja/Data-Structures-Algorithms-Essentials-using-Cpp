#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
};

vector<string> findRelativeRanks(vector<int> &score)
{
    vector<string> str(score.size(), "");
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
    for (int i = 0; i < score.size(); i++)
    {
        q.push({score[i], i});
    }
    int count = 1;
    while (!q.empty())
    {
        pair<int, int> t = q.top();
        if (count == 1)
        {
            str[t.second] = "Gold Medal";
        }
        else if (count == 2)
        {
            str[t.second] = "Silver Medal";
        }
        else if (count == 3)
        {
            str[t.second] = "Bronze Medal";
        }
        else
        {
            str[t.second] = to_string(count);
        }
        q.pop();
        count++;
    }
    return str;
}

/*
vector<int> score = {5, 4, 3, 2, 1};

vector<int> score = {10,3,8,9,4};


*/

int main()
{

    vector<int> score = {10, 3, 8, 9, 4};

    for (string x : findRelativeRanks(score))
    {
        cout << x << " ";
    }

    return 0;
}