#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int fac(int n)
{
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}

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

vector<string> helper(int n)
{
    vector<string> s;
    for (int i = 0; i < fac(n); i++)
    {
        s.push_back(decimalToBinary(i));
    }
    return s;
}

vector<string> binaryStrings(int n)
{
    // do not modify any default function or parameter you can use helper function if needed

    vector<string> s;
    s = helper(n);
    return s;
}

/*
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
*/

int main()
{
    // int n;
    // cin >> n;

    for (string x : binaryStrings(3))
    {
        cout << x << endl;
    }
    return 0;
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