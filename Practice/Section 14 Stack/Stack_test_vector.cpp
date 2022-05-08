#include <iostream>
#include "StackV.h"
using namespace std;

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    s.push(10);

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}