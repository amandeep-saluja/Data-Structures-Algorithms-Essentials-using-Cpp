#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;

    while (n > 0)
    { // loop will run only for log N times
        int last_bit = (n & 1);
        count += last_bit;
        n = (n >> 1);
    }

    return count;
}

int main()
{

    int n = 15;

    int c = countSetBits(n);

    cout << "Set bits: " << c << endl;

    return 0;
}

/*

    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        int mask = 1 << i;
        int a = (n & mask);

        if (a == mask)
            count++;
    }

    return count;

*/