#include <bits/stdc++.h>
using namespace std;

vector<bool> subsetSumOptimized(vector<int> num, vector<int> query)
{
    int N = query.size();
    vector<bool> res;

    bitset<10> b;
    b[0] = 1;

    for (int i = 0; i < num.size(); i++) {
        b = b | (b<<num[i]);
    }

    for (int i = 0; i < N; i++) {
        if(b[query[i]])
            res.push_back(true);
        else
            res.push_back(false);
    }
    return res;
}

vector<bool> subsetSum(vector<int> num, vector<int> query)
{
    int N = query.size();
    vector<bool> result;

    vector<int> prefixSum;

    for (int i = 0; i < num.size(); i++)
    {
        for (int j = i + 1; j < num.size(); j++)
        {
            int sum = num[i] + num[j];

            prefixSum.push_back(sum);
        }
    }

    for (int x : prefixSum)
    {
        cout << x << "  ";
    }
    cout << endl;

    for (int i = 0; i < N; i++)
    {
        bool found = false;
        for (int j = 0; j < prefixSum.size(); j++)
        {
            if ((prefixSum[j] ^ query[i]) == 0)
            {
                found = true;
            }
        }
        result.push_back(found);
    }

    return result;
}

int main()
{

    vector<int> num = {1, 2, 3};
    vector<int> query = {5, 3, 8, 6};

    vector<bool> res = subsetSumOptimized(num, query);

    for (bool x : res)
    {
        cout << x << " ";
    }

    return 0;
}

/*

Subset Sum Queries

Given an array and N number of queries, where in each query you have to check whether
 a subset whose sum is equal to given number exists in the array or not.

 Input Format

 In the function two vectors num and query are passed.

 Output Format

 Return a bool vector of size N representing each query.

 Sample Input

 num[]   = {1, 2, 3}
 query[] = {5, 3, 8}

 Sample Output

 {Yes, Yes, No}

 Explanation

 There is a subset with sum 5, subset is {2, 3}
 There is a subset with sum 3, subset is {1, 2}
 There is no subset with sum 8.

*/