#include <iostream>
#include <vector>
using namespace std;

bool checkSortedArray(vector<int> arr, int n) {

    if(n==0)
        return true;

    return arr[n] > arr[n-1] and checkSortedArray(arr, n-1);
}

int main()
{
    vector<int> arr = {1,2,3,4,6};

    cout << checkSortedArray(arr, arr.size()-1) << endl;

    return 0;
}