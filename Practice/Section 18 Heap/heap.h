#include <vector>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
        {
            return a < b;
        }
        else
        {
            return a > b;
        }
    }

    void heapify(int i)
    {
        int left = 2 * i;
        int right = 2 * i + 1;

        int minIdx = i;
        if (left < v.size() and compare(v[left], v[i]))
        {
            minIdx = left;
        }
        if (right < v.size() and compare(v[right], v[minIdx]))
        {
            minIdx = right;
        }

        if (minIdx != i)
        {
            swap(v[minIdx], v[i]);
            heapify(minIdx);
        }
    }

    /*
        void heapify(int i)
        {
            if (i > v.size())
                return;
            int left = 2 * i;
            int right = 2 * i + 1;

            int minIdx = min(v[left], v[right]);
            swap(v[minIdx], v[i]);
            heapify(minIdx);
        }
    */

public:
    Heap(int default_size = 10, bool minHeap = true)
    {
        v.reserve(default_size + 1);
        v.push_back(-1);
    }

    void push(int data)
    {
        // add data to end of the heap
        v.push_back(data);

        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 and compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    // return min element
    void top()
    {
        return v[1];
    }

    // Remove the min element
    void pop()
    {
        /*
            1. swap first and last element  O[1]
            2. remove last element          O[1]
            3. Heapify
        */

        int idx = v.size() - 1;

        swap(v[1], v[idx]);

        v.pop_back();

        heapify(1);
    }

    bool empty()
    {
        return v.size() == 1;
    }
};