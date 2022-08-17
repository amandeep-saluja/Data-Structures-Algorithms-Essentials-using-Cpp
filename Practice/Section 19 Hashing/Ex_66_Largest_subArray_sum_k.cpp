#include <bits/stdc++.h>
using namespace std;

int longestSubarrayKSum(vector<int> arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> m;
    int pre = 0;

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        pre += arr[i];

        if (pre == k)
        {
            len = max(len, i + 1);
        }

        if (m.find(pre - k) != m.end())
        {
            len = max(len, i - m[pre - k]);
        }
        else
        {
            // store the first occ
            m[pre] = i;
        }
    }

    return len;
}

int main()
{

    vector<int> arr = {0, -2, 1, 2, 3, 4, 5, 15, 10, 5};
    int k = 15;
    // vector<int> arr = { 1,1,1 };
    // int k = 2;
    // vector<int> arr = { 1,2,3};
    // int k = 3;

    cout << longestSubarrayKSum(arr, k);

    return 0;
}