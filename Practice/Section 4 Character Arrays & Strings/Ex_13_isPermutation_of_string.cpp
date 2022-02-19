#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool isPermutation(string A, string B) {
    if(A.length()!=B.length())
        return false;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if(A == B)
        return true;
    else
        return false;
}

int main() {

    string A = "test";
    string B = "sett";

    bool check = isPermutation(A, B);

    if(check)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}