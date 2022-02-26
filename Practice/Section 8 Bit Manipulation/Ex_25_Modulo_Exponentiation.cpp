#include <iostream>
using namespace std;

int power(int x, int y, int mod)
{
    int ans = 1;

    x = x % mod;

    if (x == 0)
    {
        return 0;
    }

    while (y > 0)
    {
        if (y & 1)
        {
            ans = (ans * x) % mod;
        }

        x = (x * x) % mod;
        y = y >> 1;
    }

    return ans;
}

int main()
{
    // 12 -> 00001100
    // 25 -> 00011001
    int x = 12, y = 25, mod = 10007;
    cout << power(x, y, mod) << endl;

    return 0;
}