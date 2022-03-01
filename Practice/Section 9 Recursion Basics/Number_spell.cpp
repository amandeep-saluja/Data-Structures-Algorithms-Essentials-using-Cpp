#include <iostream>
#include <string>
using namespace std;

string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printNumberSpell(int n) {
    if(n==0)
        return;

    int rem = n % 10;
    n = n / 10;
    printNumberSpell(n);
    cout << spell[rem] << " ";
}

int main() {

    int n;
    cin >> n;

    printNumberSpell(n);

    return 0;
}