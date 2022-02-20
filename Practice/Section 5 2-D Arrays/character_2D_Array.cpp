#include <iostream>
using namespace std;

void print(char arr[][10], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int main() {

    char arr[][10] = {
        "John",
        "Ram",
        "Kapil",
        "Singh",
        "Zenu",
        "Ankit",
        "Pushpraj",
        "Billy"
    };

    print(arr, 8);

    return 0;
}