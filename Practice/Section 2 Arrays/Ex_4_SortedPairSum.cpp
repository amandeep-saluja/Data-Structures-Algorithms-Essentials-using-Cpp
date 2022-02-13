/*
Given a sorted array and a number x, find a pair in array whose sum is closest to x.
INPUT: In the function an integer vector and number x is passed.
OUTPUT: Return a pair of integers.

SAMPLE INPUT: {10, 22, 28, 29, 30, 40} and x = 54
SAMPEL OUTPUT: 22 and 30
*/

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x)
{
    pair<int, int> sum = {0, 0};
    int minDiff = INT_MAX;

    for (int i = 0, j = arr.size(); i < j;)
    {
        int currSum = arr[i] + arr[j];
        if (minDiff > abs(x - currSum))
        {
            minDiff = abs(x - currSum);
            sum.first = arr[i];
            sum.second = arr[j];
        }
        if(currSum>x)
            j--;
        else
            i++;
    }
    return sum;
}

int main()
{

    vector<int> arr = {10, 22, 28, 29, 30, 40};

    int x = 54;

    pair<int, int> sum = closestSum(arr, x);

    cout << "Pair: " << sum.first << " and " << sum.second << endl;

    return 0;
}

/*
OLD CODE

#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    pair<int, int> pairs;
    pairs.first = -1;
    pairs.second = -1;
    vector<int> sumArray;

    int n = arr.size();
    int leftIndex = 0, rightIndex = n-1;
    int diff = INT_MAX;

    while(leftIndex < rightIndex)
    {
        // cout<<"Diff: "<<diff<<endl;
        if(abs(arr[leftIndex] + arr[rightIndex] - x ) < diff) {
            diff = abs(arr[leftIndex] + arr[rightIndex] - x);
            pairs.first = arr[leftIndex];
            pairs.second = arr[rightIndex];
            // cout<<"Pair: "<<pairs.first<<" "<<pairs.second<<endl;
        }

        if(abs(arr[leftIndex] + arr[rightIndex]) < x){
            leftIndex++;
        }
        else {
            rightIndex--;
        }
    }

    return pairs;
}

*/