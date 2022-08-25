#include <iostream>
using namespace std;

int fib(int n)
{
    int dp[n + 1] = {0};

    // base case -> assignment
    dp[0] = 0;
    dp[1] = 1;

    // bottom up dp
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fibOptimized(int n)
{
    int a = 0;
    int b = 1;
    int c = 0;

    if (n <= 1)
    {
        return n;
    }

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{

    int n;
    cin >> n;

    cout << fib(n) << endl;

    return 0;
}