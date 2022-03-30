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

    l.insert(5, 2);

    // cout << l.search(4) << endl;
    // cout << l.search(1) << endl;
    // cout << l.search(6) << endl;
    // cout << l.search(99) << endl;

    // cout << l.recursiveSearch(4) << endl;
    // cout << l.recursiveSearch(1) << endl;
    // cout << l.recursiveSearch(6) << endl;
    // cout << l.recursiveSearch(99) << endl;

    l.print();

    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;
    // cout << "Pop front: " << l.pop_front() << endl;

    // cout << "Pop back 1: " << l.pop_back() << endl;
    // cout << "Pop back 2: " << l.pop_back() << endl;
    // cout << "Pop back 3: " << l.pop_back() << endl;
    // cout << "Pop back 4: " << l.pop_back() << endl;
    // cout << "Pop back 5: " << l.pop_back() << endl;
    // cout << "Pop back 6: " << l.pop_back() << endl;

    // cout << l.remove(5) << endl;
    // l.reverse();
    cout << "Mid: " << l.midOfLinklist() << endl;

    l.print();

    return 0;
}