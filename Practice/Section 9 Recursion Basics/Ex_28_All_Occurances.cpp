#include <bits/stdc++.h>
using namespace std;

vector<int> helper(vector<int> v, vector<int> indices, int i, int k) {
    if(i==v.size())
        return indices;

    if(v[i]==k)
        indices.push_back(i);

    return helper(v, indices, ++i, k);
}

vector<int> findAllOccurences(int k, vector<int> v)
{
    vector<int> indices;
    indices = helper(v, indices, 0, k);
    return indices;
}

int main()
{
    vector<int> a = {31, 2, 5, 3, 1, 2, 3, 8, 6, 3, 6, 7, 9};
    int k = 3;

    for (int x : findAllOccurences(k, a))
    {
        cout << x << " ";
    }

    return 0;
}

/*

All Occurence!

You are given an integer array of size N.
Your aim is to find all the occurrences (indices) of a given element.

Input format:
Vector V and integer k (to find) are passed as parameters.

Output parameter:
Return a vector of integers containing all the indices in sorted manner.

Sample Input:
31 2 5 3 1 2 3 8 6 3 6 7 9

Sample Output:
3 6 9

*/