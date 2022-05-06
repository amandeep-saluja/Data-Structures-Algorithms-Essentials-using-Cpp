#include <iostream>
#include "StackLL.h"
using namespace std;

int main()
{

    Stack<char> s;
    s.push('h');
    s.push('e');
    s.push('l');
    s.push('l');
    s.push('o');

    while (!s.isEmpty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}