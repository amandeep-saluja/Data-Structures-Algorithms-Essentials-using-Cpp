#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    // Complexity O[n] + O[n] + O[nlogN] = O[nlogN]
    vector<int> num;
    unordered_set<int> s1;

    for (int i = 0; i < nums1.size(); i++)
    {
        s1.insert(nums1[i]);
    }

    for (int x : nums2)
    {
        if (s1.find(x) != s1.end())
        {
            num.push_back(x);
            s1.erase(x);
        }
    }
    sort(num.begin(), num.end());

    return num;
}

int main()
{

    vector<int> nums1{1, 2, 2, 1};

    vector<int> nums2{2, 2};

    for (int x : intersection(nums1, nums2))
    {
        cout << x << " ";
    }

    return 0;
}