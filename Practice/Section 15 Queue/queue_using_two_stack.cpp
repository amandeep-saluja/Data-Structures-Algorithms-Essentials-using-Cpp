#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1, s2;

public:
    void enqueue(int data)
    {
        s1.push(data);
    }

    int dequeue()
    {
        int data;
        while (!s1.empty())
        {
            s1.pop();
            s2.push(s1.top());
        }
        data = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return data;
    }

    int front()
    {
        int data;
        if (!s1.empty())
        {
            while (!s1.empty())
            {
                data = s1.top();
                s1.pop();
                s2.push(data);
            }

            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        return data;
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    q.dequeue();
    q.dequeue();

    while (!q.empty())
    {
        cout << q.front() << " <- ";
        q.dequeue();
    }

    return 0;
}