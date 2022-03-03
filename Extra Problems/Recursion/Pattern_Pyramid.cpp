#include <iostream>
using namespace std;

void inc(int n)
{
    if (n == 0)
        return;

    inc(n - 1);

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }

    cout << endl;
}

void pattern_print_dec(int n, int i)
{
    if (n == 0 or i > n)
        return;
    if (i < n)
    {
        cout << i << " ";
        pattern_print_dec(n, i + 1);
        return;
    }
    cout << i << endl;
    pattern_print_dec(n - 1, 1);
}

void pattern_print_inc(int n, int i)
{
    if (n == 0 or i > n)
        return;

    if (i == 1)
    {
        pattern_print_inc(n - 1, i);
    }

    cout << i << " ";
    pattern_print_inc(n, i + 1);
    if (i == n)
        cout << endl;
}

int main()
{
    pattern_print_dec(6, 1);
    pattern_print_inc(6, 1);

    return 0;
}