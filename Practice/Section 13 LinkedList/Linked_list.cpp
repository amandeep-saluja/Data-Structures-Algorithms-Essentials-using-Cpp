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

    l.print();

    return 0;
}