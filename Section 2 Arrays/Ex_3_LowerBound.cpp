/*
Given an array of integers A (sorted) and a integer Val.
Implement a function that takes A and Val as input parameters and returns the lower bound of Val.
Note:  If Val is not present in array then Lower bound of a given integer means integer which is just smaller than given integer.
Otherwise Val itself is the answer.
If Val is less than smallest element of array A then return '-1' in that case.
Sample Input: A = [-1, -1, 2, 3, 5]
Val = 4
Answer 3  =>  Since 3 is just smaller than 4 in the array.

Sample Input: A = [1, 2, 3, 4, 6]
Val = 4
Answer 4  => Since 4 is equal to 4.

*/

#include <iostream>
#include <vector>
using namespace std;

// O[n]
int lower_bound(vector<int> arr, int val)
{
    if(val<arr[0])
        return arr[0];

    int minDiff = INT_MAX, lb = INT_MAX;
    for (int x : arr)
    {
        int diff = abs(x - val);

        if (minDiff > diff)
        {
            minDiff = diff;
            lb = x;
        }
    }

    return lb;
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 6};
    int Val = 0;

    cout << "Lower bound: " << lower_bound(arr, Val);

    return 0;
}

/*
OLD CODE:

#include<bits/stdc++.h>
using namespace std;

// O[log n]

int binary_search(vector<int> arr, int key) {
    int start = 0, end = arr.size()-1;
    int index = -1;
    while(start<=end)
    {
        int mid = (start + end)/2;
        if(arr[mid] == key) {
            return mid;
        }
        else if(key < arr[mid]){
            end = mid - 1;
            index = mid;
        }
        else {
            start = mid + 1;
            index = mid;
        }
    }
    return index;
}

int lowerBound(vector<int> A, int Val) {
   int i = binary_search(A, Val);
    // cout<<"Index: "<<i;
    if(A[i] == Val)
        return Val;
    else if(A[i]>Val) {
        if(i==0) return -1;
        return A[i-1];
    }
    return A[i];
}
*/