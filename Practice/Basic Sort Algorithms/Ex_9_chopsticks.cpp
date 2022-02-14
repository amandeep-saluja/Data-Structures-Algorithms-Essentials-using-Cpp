#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    sort(length.begin(), length.end());
    int n = length.size(), count = 0;
    for (int i = 0; i < n - 1;)
    {
        if ((length[i + 1] - length[i]) <= D)
        {
            count++;
            i += 2;
        }
        else
        {
            i++;
        }
    }
    return count;
}

int main()
{
    vector<int> length = {1, 3, 3, 9, 4};
    int maxDiff = 2;

    int pairs = pairSticks(length, maxDiff);

    cout << "Max pairs can be formed: " << pairs << endl;

    return 0;
}

/*
OLD code:


#include
using namespace std;

int pairSticks(vector length, int D)
{
    vector&gt; pairs;
    int n = length.size();

    for (int i = 0, j = n - 1; i &lt; j;)
    {
        if (abs(length[i] - length[j]) &lt;= D &amp;&amp; length[j] != -1 &amp;&amp; length[i] != -1)
        {
            pairs.push_back({length[i], length[j]});
            length[i] = length[j] = -1;
            i++;
            j = n - 1;
        }
        else if (length[i] == -1)
            i++;
        else
            j--;
    }

    return pairs.size();
}

SOLUTION: 2

int pairCount = 0, n = length.size();
    // vector<pair<int, int>> sticks;
    for (int i = 0; i < n; i++)
    {
        if(length[i]==INT_MAX)
            continue;
        int j = i + 1;
        while (j < n)
        {
            if (length[j] == -1)
                j++;
            int currentDiff = D + length[i];
            if (length[j] <= currentDiff)
            {
                pairCount++;
                // sticks.push_back({length[i], length[j]});
                length[i] = length[j] = INT_MAX;
                break;
            }
            j++;
        }
    }
    // for(pair<int, int> p: sticks) {
    //     cout << p.first << " " << p.second << endl;
    // }
    return pairCount;

*/