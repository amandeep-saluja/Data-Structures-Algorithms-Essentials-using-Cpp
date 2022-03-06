#include <bits/stdc++.h>
using namespace std;

int friendsPairing(int n)
{
    if (n == 1 or n == 0)
        return 1;
    return friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main()
{

    cout << friendsPairing(4);
    // 1 -> 1
    // 2 -> 2
    // 3 -> 4
    // 4 -> 10

    return 0;
}