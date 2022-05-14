#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int getMaxArea(vector<int> hist)
{
    int maxArea = 0;
    int n = hist.size();

    vector<int> ps(n, 0);
    vector<int> ns(n, 0);

    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and hist[s.top()] > hist[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            ps[i] = s.top();
        }
        else
        {
            ps[i] = -1;
        }
        s.push(i);
    }

    printVector(ps);

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and hist[s.top()] > hist[i])
        {
            s.pop();
        }
        if (!s.empty())
        {
            ns[i] = s.top();
        }
        else
        {
            ns[i] = n;
        }
        s.push(i);
    }

    printVector(ns);

    for (int i = 0; i < n; i++)
    {
        int area = (ns[i] - ps[i] - 1) * hist[i];
        cout << area << " ";
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{

    vector<int> hist = {6, 2, 5, 4, 5, 1, 6};
                //ps   -1, -1, 1, 1, 3, -1, 5
                //ns    1,  5, 3, 5, 5,-1, -1
                //area  6, 10, 5, 12, 5, -1, -42

    cout << getMaxArea(hist);

    return 0;
}

/*
O[N^2]
int getMaxArea(vector<int> hist)
{
    int maxArea = 0;

    for (int i = 0; i < hist.size(); i++)
    {
        int left = i;
        int right = i;

        while (hist[left] >= hist[i] and left >= 0)
        {
            left--;
        }

        while (hist[right] >= hist[i] and right < hist.size())
        {
            right++;
        }

        int area = (right - left - 1) * hist[i];
        cout << "Max: " << maxArea << " area: " << area << " left: " << left << " right: " << right << endl;
        maxArea = max(area, maxArea);
    }

    return maxArea;
}
*/