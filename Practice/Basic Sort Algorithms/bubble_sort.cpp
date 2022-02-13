#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int times = 1, count = 0; times <= n - 1; times++)
    {
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
        if (count == 0)
            break;
    }
}

int main()
{

    // vector<int> arr = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    vector<int> arr = {1, 2, 3, 4, 5};
    bubbleSort(arr);
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}