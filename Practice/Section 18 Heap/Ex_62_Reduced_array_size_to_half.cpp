#include <bits/stdc++.h>
using namespace std;

class compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first < b.first;
    }
};

int minSetSize(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxHeap;
    int cnt = 1;
    int ans = 0;
    for (int i = 1; i <= arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            cnt++;
        }
        else
        {
            maxHeap.push({cnt, arr[i - 1]});
            cnt = 1;
        }
    }

    int sum = 0;
    while (arr.size() - sum > arr.size() / 2)
    {
        pair<int, int> top = maxHeap.top();
        sum += top.first;
        maxHeap.pop();
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