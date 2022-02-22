#include <iostream>
using namespace std;

int main()
{

    cout << (5 << 2) << endl;
    //   00000101
    //   00001010
    //   00010100 => 20
    cout << (256 << 2) << endl;

    cout << (11 >> 2) << endl;

    return 0;
}