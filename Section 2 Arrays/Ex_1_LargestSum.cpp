/* Implement a function that takes array of integers as input and returns the largest element.
Sample Input: -3 4 1 2 3
Sample Output: 4

Sample Input: -1 -2 -3 -3 8
Sample Output: 8
*/
#include <iostream>
#include <vector>
using namespace std;

int largest_element(vector<int> arr)
{
    int largestElement = INT_MIN;

    for (int x : arr)
    {
        largestElement = max(largestElement, x);
    }

    return largestElement;
}

int main()
{
    vector<int> arr = {-3, 4, 1, 2, 3};

    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << "\nLargest element: " << largest_element(arr) << endl;

    return 0;
}