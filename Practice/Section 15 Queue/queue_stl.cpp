#include <iostream>
#include <queue>
using namespace std;

int main()
{

    queue<int> q;
    q.push(3);
    q.push(7);
    q.push(9);
    q.push(11);
    q.push(13);
    q.push(23);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}