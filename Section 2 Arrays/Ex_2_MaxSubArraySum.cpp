/*
Implement a function that takes an array as input and returns the maximum subarray sum.
Sample Input: 1, -2, 3, 4, 4, -2
Sample Output: 11

Sample Input: 5 0 -1 0 1 2 -1
Sample Output: 7

Explanation: for test case one, A[2..4] is [3, 4, 4] and It has max sum 3 + 4 + 4 = 11,
Similarly for test case two, answer should be 7.
Note: Minimum size of the subarray should be 1.

*/

#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int> arr)
{
    int ls = 0, cs = 0;
    for (int x : arr)
    {
        cs += x;
        if (cs < 0)
            cs = 0;
        ls = max(ls, cs);
    }
    return ls;
}

int main()
{

    vector<int> arr = {5, 0, -1, 0, 1, 2, -1};

    cout << "Max Sub Array Sum: " << maxSubArraySum(arr);

    return 0;
}