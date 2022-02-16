#include <iostream>
#include <algorithm>
using namespace std;

// or use greater<int>() as inbuilt comparator for sorting in increasing order
bool compare(int a, int b) {
    return a > b;
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 11, 16, 8};
    int n = sizeof(arr) / sizeof(int);

    // sort elements from [start, end) range
    sort(arr, arr + n, compare);
    // reverse(arr, arr + n);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}