#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n)
{
    int base = 1;
    string b = "";

    while (n > 0)
    {
        int last_bit = (n & 1);
        b += last_bit * base;
        base *= 2;
        n = n >> 1;
    }
    return b;
}

int helper(int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2;

    return helper(n - 1) + helper(n - 2);
}

int binaryStrings(int n)
{
    return helper(n);
}

int main()
{
    int n;
    cin >> n;

    cout << binaryStrings(n) << endl;
}

/*

Binary Strings!

You are given an integer N.
Your task is to print all binary strings of size N without consecutive ones.

Constraints:
N<=12

Input Format

In the given function an integer N is passed as parameter.

Output Format

Return a vector of strings, with all possible strings in a sorted order.

Sample Input
3

Sample Output

000
001
010
100
101

*/