#include <iostream>
using namespace std;

void print(char arr[][10], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

int main() {

    char arr[][10] = {
        "Amandeep",
        "Anushka",
        "Amar",
        "Madhur",
        "Ankita",
        "Aniket",
        "Ishank",
        "Reena"
    };

    print(arr, 8);

    return 0;
}