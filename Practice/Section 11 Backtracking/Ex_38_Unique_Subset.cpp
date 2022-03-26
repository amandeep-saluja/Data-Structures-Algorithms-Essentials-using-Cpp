#include <bits/stdc++.h>
using namespace std;
set<vector<int>> s;

void helper(vector<int> nums, vector<int> &v, int i)
{
    // base case
    int n = nums.size();
    if (i == n)
    {
        sort(v.begin(), v.end());
        s.insert(v);
        return;
    }

    // recursive case
    v.push_back(nums[i]);
    helper(nums, v, i + 1);
    v.pop_back();
    helper(nums, v, i + 1);
}

vector<vector<int>> uniqueSubsets(vector<int> nums)
{
    s.clear();
    vector<int> v;
    helper(nums, v, 0);
    vector<vector<int>> sol;
    for (auto x : s)
    {
        sol.push_back(x);
    }
    return sol;
}

int main()
{

    vector<int> nums = {0, 1, 4};

    for (vector<int> x : uniqueSubsets(nums))
    {
        cout << "[";
        for (int y : x)
        {
            cout << y << "";
        }
        // cout << "]" ;
        cout << "], ";
    }

    return 0;
}