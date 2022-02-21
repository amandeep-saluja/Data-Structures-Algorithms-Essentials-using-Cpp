#include <iostream>
#include "vector.h"
using namespace std;

int main()
{

    Vector<char> ch;
    ch.push_back('a');
    ch.push_back('b');
    ch.push_back('c');

    for (int i = 0; i < ch.size(); i++)
    {
        cout << ch[i] << endl;
    }

    Vector<int> v(5);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    cout << v.pop_back() << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;

    cout << v.size() << endl;     // 5
    cout << v.capacity() << endl; // 8

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }

    return 0;
}