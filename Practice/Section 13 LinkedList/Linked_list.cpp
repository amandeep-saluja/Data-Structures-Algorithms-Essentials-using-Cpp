#include <iostream>
#include "List.h"
using namespace std;

int main()
{

    List l;
    l.push_front(1);
    l.push_front(3);
    l.push_front(4);
    l.push_back(2);
    l.push_back(6);

    l.insert(5, 12);

    // cout << l.search(4) << endl;
    // cout << l.search(1) << endl;
    // cout << l.search(6) << endl;
    // cout << l.search(99) << endl;

    cout << l.recursiveSearch(4) << endl;
    cout << l.recursiveSearch(1) << endl;
    cout << l.recursiveSearch(6) << endl;
    cout << l.recursiveSearch(99) << endl;

    l.print();

    return 0;
}