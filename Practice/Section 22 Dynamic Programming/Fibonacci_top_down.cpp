#include <iostream>
using namespace std;

int fib(int n, int dp[])
{
    if (n == 0 or n == 1)
    {
        return n;
    }

    // Check if the state is already computed
    if (dp[n] != 0)
    {
        return dp[n];
    }

    // otherwise compute the state and store it
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;

    int dp[n + 1] = {0};

    cout << "Fabionacci of " << n << "th number: " << fib(n, dp) << endl;

    return 0;
}