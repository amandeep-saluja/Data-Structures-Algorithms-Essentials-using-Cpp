#include <iostream>
using namespace std;

int main()
{

    int x = 5;
    int *xptr = &x;

    float y = 5.5;


    cout << &x << endl;
    cout << xptr << endl;
    cout << &xptr << endl;
    cout << *xptr << endl;

    return 0;
}