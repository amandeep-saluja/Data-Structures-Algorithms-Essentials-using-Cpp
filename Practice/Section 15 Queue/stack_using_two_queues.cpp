#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    bool empty()
    {
        // cout << "empty? " << (q1.empty() and q2.empty()) << endl;
        return q1.empty() and q2.empty();
    }

    int top()
    {
        if (!q1.empty())
        {
            while (!q1.empty())
            {
                int front = q1.front();
                q2.push(front);
                q1.pop();

                if (q1.empty())
                {
                    return front;
                }
            }
        }
        else
        {
            while (!q2.empty())
            {
                int front = q2.front();
                q1.push(front);
                q2.pop();

                if (q2.empty())
                {
                    return front;
                }
            }
        }
    }

    void push(int data)
    {
        cout << "Push: " << data;
        if (!q1.empty())
        {
            cout << " in q1" << endl;
            q1.push(data);
        }
        else
        {
            cout << " in q2" << endl;
            q2.push(data);
        }
    }
    void pop()
    {
        if (!q1.empty())
        {
            while (!q1.empty())
            {
                int front = q1.front();
                q1.pop();

                if (q1.empty())
                {
                    break;
                }
                q2.push(front);
            }
        }
        else
        {
            while (!q2.empty())
            {
                int front = q2.front();
                q2.pop();

                if (q2.empty())
                {
                    break;
                }
                q1.push(front);
            }
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.push(5);
    s.push(6);
    s.pop();
    s.push(9);
    s.push(15);

    while (!s.empty())
    {
        cout << s.top() << " -> ";
        s.pop();
    }

    return 0;
}