#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> arr, int s, int e, int x)
{
    // base case
    if (s > e)
    {
        return -1;
    }

    // recursive case

    int mid = (s + e) / 2;
    if (x == arr[mid])
    {
        return mid;
    }
    else if (x < arr[mid])
    {
        return binary_search(arr, s, mid - 1, x);
    }
    else
    {
        return binary_search(arr, mid + 1, e, x);
    }
}

int main()
{
    vector<int> arr = {1, 4, 8, 11, 14, 21, 36, 44, 56};
    int x = 11;

    // vector<int> arr = {1, 3, 5, 7, 9};
    // int x = 3;

    cout << x << " is present at index " << binary_search(arr, 0, arr.size() - 1, x) << endl;

    return 0;
}

/*

Binary Search using Recursion!

Given a sorted array, return the index of an element x in the array.
Use binary search to find the element in the array !Return -1 if the element is not present.

Input Format

In the function an integer vector  is passed.

Output Format

Return an integer denoting index of the element to be find.

Sample Input

{1, 3, 5, 7, 9}, x = 3

Sample Output 1

Explanation

3 is present at index 2.

*/