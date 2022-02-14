#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortWithComparator(vector<int> &arr, bool flag) {
    if(flag)
        sort(arr.begin(), arr.end());
    else
        sort(arr.begin(), arr.end(), greater<int>());
}

int main() {

    vector<int> arr = {111, 35, 5, 7, 29};
    bool flag = 0;

    sortWithComparator(arr, flag);

    for(int x: arr) {
        cout << x << " ";
    }

    return 0;
}