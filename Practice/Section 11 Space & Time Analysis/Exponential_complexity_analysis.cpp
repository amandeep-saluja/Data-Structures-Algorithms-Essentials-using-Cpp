#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

vector<int> take_input(int n)
{
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
    return arr;
}

void inbuild_sort(vector<int> arr)
{
    auto start_time = clock();
    sort(arr.begin(), arr.end());
    auto end_time = clock();
    // cout << start_time << endl;
    // cout << end_time << endl;
    cout << "For " << arr.size() << ": " << end_time - start_time << endl;
}

void bubbleSort(vector<int> arr)
{
    auto start_time = clock();
    int n = arr.size();
    for (int times = 1; times <= n - 1; times++)
    {
        for (int j = 0; j <= n - times - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    auto end_time = clock();
    cout << "For " << arr.size() << ": " << end_time - start_time << endl;
}

int main()
{

    int n;
    n = 100;
    inbuild_sort(take_input(n));
    n = 1000;
    inbuild_sort(take_input(n));
    n = 10000;
    inbuild_sort(take_input(n));
    n = 100000;
    inbuild_sort(take_input(n));
    n = 1000000;
    inbuild_sort(take_input(n));
    n = 10000000;
    inbuild_sort(take_input(n));

    n = 100;
    bubbleSort(take_input(n));
    n = 1000;
    bubbleSort(take_input(n));
    n = 10000;
    bubbleSort(take_input(n));
    n = 100000;
    bubbleSort(take_input(n));
    n = 1000000;
    bubbleSort(take_input(n));
    n = 10000000;
    bubbleSort(take_input(n));

    return 0;
}
/*
Result:
For 100: 0
For 1000: 0
For 10000: 4
For 100000: 61
For 1000000: 460
For 10000000: 4012
For 100: 0
For 1000: 20
For 10000: 1464
For 100000: 179428
*/