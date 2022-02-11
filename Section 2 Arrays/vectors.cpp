#include <iostream>
#include <vector>
using namespace std;

int main() {

    // vector<int> arr = {1, 2, 21, 0, 6, 8};
    vector<int> arr(10, 7);

    cout << arr.size() << endl;

    cout << arr.capacity() << endl;
    arr.push_back(3);
    cout << arr.capacity() << endl;

    for(int i: arr) {
        cout << i << "\t";
    }

    return 0;
}