#include <iostream>
using namespace std;

void inc(int n, int i)
{
    if (n == 0 or n < i)
        return;

    if (i == 1)
        inc(n - 1, 1);

    cout << i << " ";
    inc(n, i + 1);

    if (n == i)
        cout << endl;
}

void dec(int n, int i)
{
    if (n == 0 or n < i)
        return;

    cout << i << " ";
    dec(n, i + 1);

    if (i == 1)
        dec(n - 1, 1);

    if (n == i)
        cout << endl;
}

int main()
{
    inc(6, 1);
    dec(6, 1);

    return 0;
}