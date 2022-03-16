#include <iostream>
using namespace std;

bool isPalindromeEff(int x)
{
    if (x < 0 or (x % 10 == 0 and x != 0))
        return false;

    int rev = 0;
    while (x > rev)
    {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    cout << rev << " " << x << endl;
    if (x == rev or x == rev / 10)
        return true;
    return false;
}

// Fails if we provide input greater than INT.MAX
bool isPalindrome(int x)
{
    int rev = 0, num = x;
    while (num != 0)
    {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    if (rev == x)
        return true;
    return false;
}

int main()
{
    string s = isPalindromeEff(121) ? "true" : "false";

    cout << s;

    return 0;
}