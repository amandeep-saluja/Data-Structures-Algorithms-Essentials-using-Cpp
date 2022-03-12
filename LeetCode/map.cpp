#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int square(int x)
{
    return x * x;
}

int main()
{
    map<int, int> squares;

    for (int i = 1; i < 10; i++)
    {
        squares.insert(i, square(i));
    }

    

    cout << squares << endl;

    return 0;
}