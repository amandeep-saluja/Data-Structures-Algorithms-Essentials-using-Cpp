#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr, int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}

void fillVector(vector<int> &arr, int i, int n, int val)
{
    // base case
    if (n == i)
    {
        // print out Vector
        printVector(arr, n);
        return;
    }
    // recursive case
    arr[i] = val;
    fillVector(arr, i + 1, n, val + 1);
    // backtracking step
    arr[i] = -1 * arr[i];
}

int main()
{

    vector<int> arr(100, 0);
    int n;
    cin >> n;

    fillVector(arr, 0, n, 1);
    printVector(arr, n);

    return 0;
}