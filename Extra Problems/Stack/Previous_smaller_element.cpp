#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> previousSmallerElement(vector<int> a)
{
    vector<int> prev;
    stack<int> s;

    for (int i = 0; i < a.size(); i++)
    {
        while (!s.empty() and s.top() > a[i])
        {
            s.pop();
        }
        if(!s.empty()) {
            prev.push_back(s.top());
            // s.pop();
        }
        else {
            prev.push_back(-1);
        }
        s.push(a[i]);
    }

    return prev;
}

int main()
{
    vector<int> arr = {4, 10, 5, 8, 20, 15, 3, 12};
                    // -1, 4, 4, 5, 8, 8, -1, 3

    vector<int> brr = {5, 15, 20, 25, 12, 20};
                    // -1, 5, 15, 20, 5, 12

    for(int x:previousSmallerElement(arr)) {
        cout << x << " ";
    }
    cout << endl;
    for(int x: previousSmallerElement(brr)) {
        cout << x << " ";
    }
    

    return 0;
}