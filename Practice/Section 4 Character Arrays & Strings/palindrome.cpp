#include <iostream>
#include <cstring>
using namespace std;

bool check_palindrome(char str[]) {

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        if(str[i]!=str[j])
            return false;
    }

    return true;
}

int main() {

    char str[1000];
    cout << "Enter a string: ";
    cin >> str;

    bool isPalindrome = check_palindrome(str);
    if(isPalindrome)
        cout << "String is a palindrome" << endl;
    else
        cout << "String is not a palindrome" << endl;

    return 0;
}