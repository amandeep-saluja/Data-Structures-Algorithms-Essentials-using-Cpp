#include <iostream>
using namespace std;

int main()
{

    int x;
    cin >> x;

    if (x & 1)
    {
        cout << x << " is odd.";
    }
    else
    {
        cout << x << " is even.";
    }

    return 0;
}