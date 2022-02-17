#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    // string s = "abcde";
    // string obj("efghij");
    string inputString;
    vector<string> sarr;
    int n = 5;

    while(n--) {
        getline(cin, inputString);
        sarr.push_back(inputString);
    }

    // getline(cin, inputString, '.');

    // cout << s << endl;
    // cout << obj << endl;
    // cout << inputString << endl;

    for(string s: sarr) {
        cout << s << endl;
    }

    return 0;
}