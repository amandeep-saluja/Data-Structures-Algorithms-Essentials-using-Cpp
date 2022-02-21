#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> arr = {10, 11, 2, 3, 4, 6, 7, 8};
    int key = 1;

    vector<int>::iterator it = find(arr.begin(), arr.end(), key);

    if(it!=arr.end())
        cout <<"Present at index "<< it - arr.begin() << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}