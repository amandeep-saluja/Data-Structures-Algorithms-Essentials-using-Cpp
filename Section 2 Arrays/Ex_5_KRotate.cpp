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

void reverse(vector<int> &num, int low, int high)
{
    while (low < high)
    {
        swap(num[high], num[low]);
        high--;
        low++;
    }
}

vector<int> kRotate(vector<int> a, int k)
{
    int n = a.size();
    k = k % n;
    reverse(a, 0, n - k - 1);
    reverse(a, n - k, n - 1);
    reverse(a, 0, n - 1);
    return a;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 4;

    for (int i : arr)
    {
        cout << i << "\t";
    }

    vector<int> brr = kRotate(arr, x);

    cout << endl;

    for (int i : brr)
    {
        cout << i << "\t";
    }

    return 0;
}

/*
Solution 1:

vector<int> b;
    for (int i = 0, j=a.size()-k; i < a.size(); i++) {
        if(j==a.size()) {
            j = 0;
        }
        b.push_back(a[j]);
        j++;
    }
    return b;
*/