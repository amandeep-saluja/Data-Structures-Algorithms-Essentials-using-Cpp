#include <iostream>
using namespace std;

int firstOccurance(int arr[], int n, int key)
{
    // base case:
    if (n == 0)
        return -1;

    if (arr[0] == key)
    {
        return 0;
    }

    int index = firstOccurance(arr + 1, --n, key);

    if (index != -1)
        return index + 1;
    else
        return -1;
}

int main()
{

    int arr[] = {1, 3, 5, 7, 6, 2};
    int n = sizeof(arr) / sizeof(int);
    int key = 171;

    cout << "Position of key: " << firstOccurance(arr, n, 17) + 1 << endl;

    return 0;
}