#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{

    Queue q;
    // cout << q.front() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.printQueue();

    q.pop();
    q.printQueue();

    return 0;
}