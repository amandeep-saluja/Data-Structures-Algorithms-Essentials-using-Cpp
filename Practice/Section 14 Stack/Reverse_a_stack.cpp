#include <iostream>
#include <stack>
using namespace std;

void insertAtLast(stack<int> &s, int data)
{
    if (s.empty())
    {
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtLast(s, data);
    s.push(temp);
}

void reverse_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int temp = s.top();
    s.pop();
    reverse_stack(s);
    insertAtLast(s, temp);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverse_stack(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}