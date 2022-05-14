#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> a)
{
    vector<int> prev(a.size(), 0);
    stack<int> s;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        while (!s.empty() and s.top() < a[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            prev[i] = s.top();
            // s.pop();
        }
        else
        {
            prev[i] = -1;
        }
        s.push(a[i]);
    }

    return prev;
}

int main()
{
    vector<int> arr = {4, 10, 5, 8, 20, 15, 3, 12};
                    // 10, 20, 8, 20, -1, -1, 12, -1

    vector<int> brr = {5, 15, 20, 25, 12, 20};
                    // 15, 20, 25, -1, 20, -1

    for (int x : nextGreaterElement(arr))
    {
        cout << x << " ";
    }
    cout << endl;
    for (int x : nextGreaterElement(brr))
    {
        cout << x << " ";
    }

    return 0;
}