#include <iostream>
#include <queue>
using namespace std;

queue<int> interLeave(queue<int> q)
{
    queue<int> q1, q2;
    int n = q.size();
    int i = 0;
    while (i < n / 2)
    {
        cout << "i: " << i << endl;
        q1.push(q.front());
        q.pop();
        i++;
    }
    while (i < n)
    {
        cout << "i:: " << i << endl;
        q2.push(q.front());
        q.pop();
        i++;
    }

    while (!q1.empty() and !q2.empty())
    {
        q.push(q1.front());
        q.push(q2.front());
        q1.pop();
        q2.pop();
    }
    return q;
}

int main()
{

    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    q = interLeave(q);

    while (!q.empty())
    {
        cout << q.front() << " <-";
        q.pop();
    }

    return 0;
}