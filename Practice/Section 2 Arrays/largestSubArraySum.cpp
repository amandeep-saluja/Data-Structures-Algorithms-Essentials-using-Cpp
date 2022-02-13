#include <iostream>
using namespace std;
// Brute force approach
void printLargestSubArraySum1(int arr[], int n)
{
    int largestSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                // cout << arr[k] << ",";
                sum += arr[k];
            }
            largestSum = max(largestSum, sum);
            // cout << "   ";
            // cout << "Sum: " << sum << endl;
        }
    }
    cout << "Largest sum: " << largestSum << endl;
}

// Prefix sum approach

void printLargestSubArraySum2(int arr[], int n)
{
    int largestSum = INT_MIN;
    int prefixArray[n] = {0};

    prefixArray[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefixArray[i] = prefixArray[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = i > 0 ? prefixArray[j] - prefixArray[i - 1] : prefixArray[j];
            // cout << "Sum: " << sum << endl;
            largestSum = max(largestSum, sum);
        }
    }
    cout << "Largest Sum: " << largestSum << endl;
}

// Kadane's algorithm O[n]

void printLArgestSubArraySum3(int arr[], int n)
{
    int cs = 0, ls = 0;

    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        if (cs < 0)
        {
            cs = 0;
        }

        ls = max(ls, cs);
    }

    cout << "Largest Sum: " << ls << endl;
}

int main()
{

    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    printLargestSubArraySum1(arr, n);
    printLargestSubArraySum2(arr, n);
    printLArgestSubArraySum3(arr, n);

    return 0;
}