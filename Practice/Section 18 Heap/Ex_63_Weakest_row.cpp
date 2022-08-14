#include <bits/stdc++.h>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
{
    vector<int> warr;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int m = mat.size(), n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                cnt++;
            }
        }
        q.push({cnt, i});
    }

    while (k > 0)
    {
        pair<int, int> p = q.top();
        warr.push_back(p.second);
        q.pop();
        k--;
    }

    return warr;
}

/*

4 4
1 0 0 0
1 1 1 1
1 0 0 0
1 0 0 0
2

5 5
1 1 0 0 0
1 1 1 1 0
1 0 0 0 0
1 1 0 0 0
1 1 1 1 1
3

*/

int main()
{

    int m, n;
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    int k;
    cin >> k;

    for (int x : kWeakestRows(mat, k))
    {
        cout << x << " ";
    }

    return 0;
}