#include <iostream>
using namespace std;

int fabonacci(int n)
{
    // cout << n << " ";

    if (n == 0 or n == 1)
        return n;
    return fabonacci(n - 1) + fabonacci(n - 2);
}

int main()
{
    // 0, 1, 1, 2, 3, 5, 8, 13, 21
    int n;
    cin >> n;

    cout << fabonacci(n);

    return 0;
}