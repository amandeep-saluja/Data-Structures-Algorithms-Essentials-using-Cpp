#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    vector<int> brr;
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    // copy both arrays into brr and stop if one of them is over
    while (i <= mid and j <= e)
    {
        if (arr[i] < arr[j])
        {
            brr.push_back(arr[i]);
            i++;
        }
        else
        {
            brr.push_back(arr[j]);
            j++;
        }
    }
    // copy left over values of either of the arrays
    while (i <= mid)
    {
        brr.push_back(arr[i]);
        i++;
    }
    while (j <= e)
    {
        brr.push_back(arr[j]);
        j++;
    }

    for (int index = s, k = 0; index <= e; index++, k++)
    {
        arr[index] = brr[k];
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
        return;
    // recursive case
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    return merge(arr, s, e);
}

int main()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    int s = 0;
    int e = arr.size() - 1;

    mergeSort(arr, s, e);
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}