#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> nums, set<vector<int>> &subsets, vector<int> &v, int j)
{
    // base case
    int n = nums.size();
    if (j >= n)
    {
        subsets.insert(v);
        sort(v.begin(), v.end());
        return;
    }

    // recursive case
    // cout << "j: " << j << endl;
    v.push_back(nums[j]);
    helper(nums, subsets, v, j + 1);
    v.pop_back();
    helper(nums, subsets, v, j + 1);
}

vector<vector<int>> uniqueSubsets(vector<int> nums)
{
    set<vector<int>> subsets;
    vector<int> v;
    helper(nums, subsets, v, 0);
    vector<vector<int>> sol(subsets.begin(), subsets.end());
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