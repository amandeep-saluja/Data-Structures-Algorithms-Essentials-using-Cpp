#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int ms;
    int cs;

    int frontIdx;
    int rearIdx;

    Queue(int default_size = 5)
    {
        ms = default_size;
        arr = new int[ms];
        cs = 0;

        frontIdx = 0;
        rearIdx = ms - 1;
    }

    bool isFull()
    {
        return cs == ms;
    }

    bool isEmpty()
    {
        return cs == 0;
    }

    void push(int data)
    {
        if (!isFull())
        {
            // take rear to next index
            rearIdx = (rearIdx + 1) % ms;
            arr[rearIdx] = data;
            cs++;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            frontIdx = (frontIdx + 1) % ms;
            cs--;
        }
    }

    int front()
    {
        return arr[frontIdx];
    }

    int rear()
    {
        return arr[rearIdx];
    }

    void printQueue()
    {
        int i = frontIdx;
        while (i <= rearIdx)
        {
            cout << arr[i] << " -> ";
            i++;
        }
        cout << endl;
    }
};