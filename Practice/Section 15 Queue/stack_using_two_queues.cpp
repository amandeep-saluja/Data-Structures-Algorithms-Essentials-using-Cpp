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
        // cout << "Top" << endl;
        if (!q1.empty() and q2.empty())
        {
            return q1.back();
        }
        else if (q1.empty() and !q2.empty())
        {
            return q2.back();
        }
        return -1;
    }

    void push(int data)
    {
        cout << "Push: " << data;
        if ((!q1.empty() and q2.empty()) or (q1.empty() and q2.empty()))
        {
            cout << " in q1" << endl;
            q1.push(data);
        }
        else if (q1.empty() and !q2.empty())
        {
            cout << " in q2" << endl;
            q2.push(data);
        }
    }
    void pop()
    {
        // cout << "Pop" << endl;
        if (!q1.empty() and q2.empty())
        {
            while (!q1.empty())
            {
                if (q1.front() != q1.back())
                    q2.push(q1.front());
                q1.pop();
            }
        }
        else if (q1.empty() and !q2.empty())
        {
            while (!q2.empty())
            {
                if (q2.front() != q2.back())
                    q1.push(q2.front());
                q2.pop();
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