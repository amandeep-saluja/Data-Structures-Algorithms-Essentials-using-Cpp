#include <iostream>
using namespace std;

int lastOccurance(int arr[], int n, int key)
{

    if(n==0)
        return -1;

    int index = lastOccurance(arr+1, --n, key);
    if (index!=-1)
        return index + 1;

    if(arr[0]==key)
        return 0;

    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 6, 2, 3, 3};
    int n = sizeof(arr) / sizeof(int);
    int key = 0;

    cout << "Position of key: " << lastOccurance(arr, n, 13) << endl;

    return 0;
}