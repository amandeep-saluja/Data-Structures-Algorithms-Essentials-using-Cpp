#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void fillArray(int *arr, int i, int n, int val)
{
    // base case
    if (n == i)
    {
        // print out array
        printArray(arr, n);
        return;
    }
    // recursive case
    arr[i] = val;
    fillArray(arr, i + 1, n, val + 1);
    // backtracking step
    arr[i] = -1 * arr[i];
}

int main()
{

    int arr[100] = {0};
    int n;
    cin >> n;

    fillArray(arr, 0, n, 1);
    printArray(arr, n);

    return 0;
}