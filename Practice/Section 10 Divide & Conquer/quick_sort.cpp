#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int i = s - 1;
    int pivot = arr[e];

    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[j], arr[++i]);
        }
    }
    swap(arr[++i], arr[e]);
    return i;
}

void quickSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // recursive case
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
    cout << arr.size() << endl;
    int n = arr.size() - 1;

    quickSort(arr, 0, n);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}