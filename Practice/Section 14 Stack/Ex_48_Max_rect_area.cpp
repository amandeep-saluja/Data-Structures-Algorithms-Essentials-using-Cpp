#include <bits/stdc++.h>
using namespace std;

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

int main()
{

    vector<int> hist = {6, 2, 5, 4, 5, 1, 6};

    cout << getMaxArea(hist);

    return 0;
}