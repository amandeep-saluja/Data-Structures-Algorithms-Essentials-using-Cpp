#include <bits/stdc++.h>
using namespace std;

int minSetSize(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> map;
    priority_queue<int> q;

    for (int x : arr)
    {
        map[x]++;
    }

    for (auto p : map)
    {
        q.push(p.second);
    }

    int sum = 0, ans = 0;
    while (n - sum > n / 2)
    {
        sum += q.top();
        q.pop();
        ans++;
    }
    return ans;
}

int main()
{

    int N;
    cin >> N;

    vector<int> arr(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << minSetSize(arr);

    return 0;
}