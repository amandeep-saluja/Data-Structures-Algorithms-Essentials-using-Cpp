#include <iostream>
using namespace std;

int main()
{

    cout << (5 & 7) << endl;
    //   00000101
    //   00000111
    // =>00000101

    cout << (5 | 7) << endl;
    //   00000101
    //   00000111
    // =>00000111

    cout << (5 ^ 7) << endl;
    //   00000101
    //   00000111
    // =>00000010

    cout << (~5) << endl;
    //   00000101
    //   11111010
    // =>1 0000101+1 = -6

    return 0;
}