#include <iostream>
using namespace std;

int power(int x, int y, int mod)
{
    return (x ^ y) % mod;
}

int main()
{

    int x = 12, y = 25, mod = 10007;

    cout << power(x, y, mod) << endl;

    return 0;
}