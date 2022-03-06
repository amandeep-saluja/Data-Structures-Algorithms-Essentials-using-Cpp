#include <iostream>
#include <vector>
using namespace std;

int rotated_search(vector<int> arr, int key)
{
    int n = arr.size();

    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (key == arr[mid])
            return mid;

        // 2 cases

        if (arr[s] <= arr[mid])
        {
            if (key >= arr[s] and key <= arr[mid])
            {
                // Left
                e = mid - 1;
            }
            else
            {
                // Right
                s = mid + 1;
            }
        }
        else if (arr[mid] <= arr[e])
        {
            if (key >= arr[mid] and key <= arr[e])
            {
                // Right
                s = mid + 1;
            }
            else
            {
                // Left
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{

    vector<int> arr{4, 5, 6, 7, 0, 1, 2, 3};
    int key;
    cin >> key;

    cout << rotated_search(arr, key) << endl;

    return 0;
}