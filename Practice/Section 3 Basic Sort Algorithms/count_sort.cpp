#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &arr)
{
    int n = arr.size();
    int largest_element = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        largest_element = max(largest_element, arr[i]);
    }
    vector<int> count(largest_element + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[arr[i]] += 1;
    }

    for (int i = 0, j = 0; i < count.size(); i++)
    {
        while (count[i]--)
        {
            arr[j] = i;
            j++;
        }
    }
}

int main()
{

    vector<int> arr = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};

    countSort(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}