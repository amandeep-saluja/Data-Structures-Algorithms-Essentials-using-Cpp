#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1, j=i; i < n; i++)
    {
        int temp = arr[i];
        //loop to shift elements
        for (j = i-1; j >= 0; j--) {
            if(temp>arr[j]) {
                //break and swap
                break;
            }
            else {
                // shift one element
                swap(arr[j], arr[j + 1]);
            }
        }
        arr[j + 1] = temp;
    }
}

int main()
{

    vector<int> arr = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    // vector<int> arr = {1, 2, 3, 4, 5};
    insertionSort(arr);
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}