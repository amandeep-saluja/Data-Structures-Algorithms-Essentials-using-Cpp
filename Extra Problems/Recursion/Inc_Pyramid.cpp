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

void pattern_print(int n, int i)
{
    if (n == 0 or i > n)
        return;
    if (i < n)
    {
        cout << i << " ";
        pattern_print(n, i + 1);
        return;
    }
    cout << i << endl;
    pattern_print(n - 1, 1);
}

int main()
{
    pattern_print(6, 1);

    return 0;
}