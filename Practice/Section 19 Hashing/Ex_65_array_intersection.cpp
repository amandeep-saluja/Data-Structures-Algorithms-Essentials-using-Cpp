#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> num;
    unordered_set<int> s1;
    unordered_set<int> s2;

    for (int i = 0; i < nums1.size(); i++)
    {
        s1.insert(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        s2.insert(nums2[i]);
    }

    for (int x : s1)
    {
        if (s2.find(x) != s2.end())
        {
            num.push_back(x);
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