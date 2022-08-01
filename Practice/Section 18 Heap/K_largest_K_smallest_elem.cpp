#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int findKthSmallestElement(vector<int> v, int k)
{
    priority_queue<int> maxHeap(v.begin(), v.begin() + k);
    for (int i = k; i < v.size(); i++)
    {
        if (maxHeap.top() > v[i])
        {
            maxHeap.pop();
            maxHeap.push(v[i]);
        }
    }
    return maxHeap.top();
}

int findKthLargestElement(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap(v.begin(), v.begin() + k);
    for (int i = k; i < v.size(); i++)
    {
        if (minHeap.top() < v[i])
        {
            minHeap.pop();
            minHeap.push(v[i]);
        }
    }
    return minHeap.top();
}

/*
Input:
6 3
7 10 4 3 20 15
*/

/*
Output:
7
10
*/

int main()
{

    int N, K;
    cin >> N >> K;

    vector<int> v(N, 0);
    int d;
    for (int i = 0; i < N; i++)
    {
        cin >> d;
        v[i] = d;
    }

    cout << findKthSmallestElement(v, K) << endl;
    cout << findKthLargestElement(v, K);

    return 0;
}