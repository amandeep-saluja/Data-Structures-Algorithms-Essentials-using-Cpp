#include <iostream>
using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

void bubbleSortRec(int arr[], int n)
{
    if (n == 1)
        return;

    for (int j = 0; j < n - 1; j++)
    {
        if (compare(arr[j], arr[j + 1]))
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    bubbleSortRec(arr, n - 1);
}

void bubbleSortRec2(int arr[], int n, int j)
{
    if (n == 1 or n==0)
        return;

    if (j == n - 1)
    {
        bubbleSortRec2(arr, n-1, 0);
        return;
    }

    if (compare(arr[j], arr[j + 1]))
    {
        swap(arr[j], arr[j + 1]);
    }
    bubbleSortRec2(arr, n, j+1);
}

int main()
{

    int arr[] = {5, 4, 3, 2, 1};
    // int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    bubbleSortRec2(arr, n, 0);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}