#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int times = 1; times <= n - 1; times++)
    {
        int minIndex = times;
        // find minimum in the remaining array
        for (int j = times + 1; j <= n - 1; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // swap the current times element with minIndex element
        swap(arr[minIndex], arr[times - 1]);
    }
}

int main()
{

    vector<int> arr = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    // vector<int> arr = {1, 2, 3, 4, 5};
    selectionSort(arr);
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}