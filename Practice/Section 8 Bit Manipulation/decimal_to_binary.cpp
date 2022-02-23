#include <iostream>
using namespace std;

int decimalToBinary(int n)
{
    int b = 0;
    int power = 1;

    while (n > 0)
    {
        int last_bit = (n & 1);
        b += power * last_bit;
        power *= 10;
        n = n >> 1;
    }

    return b;
}

int main()
{

    int n;
    cin >> n;

    int a = decimalToBinary(n);

    cout << a << endl;

    return 0;
}