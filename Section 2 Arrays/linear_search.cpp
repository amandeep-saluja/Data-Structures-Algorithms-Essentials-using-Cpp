#include <iostream>
using namespace std;

int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i+1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 0, 10, 11, 9, 8, 8, 7};
    int size = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    cout << linear_search(arr, size, key);
    return 0;
}