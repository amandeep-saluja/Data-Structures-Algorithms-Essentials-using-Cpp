/*
Given an integer vector and a value k, your task is to rotate the array k times clockwise.
INPUT: In the function an integer vector and number k is passed.

OUTPUT: Return an integer vector.

SAMPLE INPUT: {1,3,5,7,9}, x=2
SAMPLE OUTPUT: {7,9,1,3,5}

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
    
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 2;

    for (int i : arr)
    {
        cout << i << "\t";
    }

    vector<int> brr = kRotate(arr, x);

    for (int i : brr)
    {
        cout << i << "\t";
    }

    return 0;
}