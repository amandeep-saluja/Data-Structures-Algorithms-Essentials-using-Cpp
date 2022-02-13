#include <iostream>;
using namespace std;

int binary_search(int arr[], int n, int key)
{

    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
    /*
    int start = 0, end = n, mid = (start + end + 1) / 2;

    while (start <= end)
    {
        if (key < arr[mid])
        {
            end = mid - 1;
            mid = (start + end + 1) / 2;
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
            mid = (start + end + 1) / 2;
        }
        else
        {
            return mid;
        }
    }

    return -1;
    */
}

int main()
{

    int arr[] = {1, 5, 7, 9, 11, 13, 15, 17, 23};

    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    int index = binary_search(arr, n, key);

    if (index != -1)
        cout << "\nPresent at index : " << index << endl;
    else
        cout << "\nNot found" << endl;

    return 0;
}