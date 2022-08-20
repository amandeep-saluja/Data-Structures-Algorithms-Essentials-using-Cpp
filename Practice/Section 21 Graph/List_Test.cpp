#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);

    for (int x : lt)
    {
        cout << x << "-->";
    }

    list<int> *l = new list<int>;

    l->push_back(1);
    l->push_back(2);
    l->push_back(3);
    l->push_back(4);
    l->push_back(5);
    l->push_back(6);
    l->push_back(7);

    cout << endl;

    for (list<int>::iterator it = l->begin(); it != l->end(); it++)
    {
        cout << *it << "->";
    }

    return 0;
}