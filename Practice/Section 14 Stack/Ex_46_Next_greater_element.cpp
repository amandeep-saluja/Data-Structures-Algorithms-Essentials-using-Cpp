#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> nextGreaterElement(vector<int> v)
{
    vector<int> n;
    stack<int> s;

    for (int i = 0, j = 0; i < v.size(); i++)
    {
        int curr = v[i];
        while (curr > v[++j] and j < v.size())
        {
        }
        if (j < v.size())
        {
            s.push(v[j]);
        }
        else
        {
            s.push(-1);
        }
        j = i + 1;
    }
    while (!s.empty())
    {
        n.push_back(s.top());
        s.pop();
    }
    reverse(n.begin(), n.end());
    return n;
}

int main()
{
    vector<int> n = {4, 5, 12, 25, 3, 1, 2, 9, 0};

    for (int x : nextGreaterElement(n))
    {
        cout << x << " ";
    }

    return 0;
}
/*

Next Greater Element

Given an array, return the Next Greater Element for every element.
The Next greater Element for an element x is the first greater element
on the right side of x in the array. Elements for which no greater element exist,
consider the next greater element as -1.

Input Format
In the function an integer vector is passed

Output Format
Return an integer vector containing the next greater element for each element

Sample Input
v = { 4, 5, 2, 25 }

Sample Output
{ 5, 25, 25, -1 }

*/