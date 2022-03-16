#include <iostream>
using namespace std;

int reverse(int num)
{
    int rev = 0;
    while (num != 0)
    {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }
    return rev;
}

int main()
{

    int num = 1234;
    cout << reverse(num) << endl;

    return 0;
}