#include <iostream>
#include "heap.h"
using namespace std;

int main()
{

    Heap h(8, false);
    h.push(50);
    h.push(90);
    h.push(70);
    h.push(60);
    h.push(80);
    h.push(100);
    h.push(20);

    h.print();

    h.pop();
    h.print();
    h.pop();

    h.print();

    return 0;
}