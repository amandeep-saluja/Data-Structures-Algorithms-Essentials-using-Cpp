#include <bits/stdc++.h>
using namespace std;

int reverse(int n)
{
    stack<int> s;
    while (n)
    {
        s.push(n % 10);
        n = n / 10;
    }

    int base = 1;
    while (!s.empty())
    {
        cout << "n: " << n << " " << s.top() << endl;
        n = n + s.top()*base;
        s.pop();
        base *= 10;
    }

    return n;
}

int main()
{

    int x = 456;

    cout << reverse(x) << endl;

    return 0;
}