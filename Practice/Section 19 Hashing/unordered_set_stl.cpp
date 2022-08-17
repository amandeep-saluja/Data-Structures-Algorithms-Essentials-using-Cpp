#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // set is just a collection of keys
    // each insertion is O(1)
    unordered_set<int> s{1, 2, 3, 8, 11, 15, 0};

    // insert O(1)
    s.insert(111);

    // erase O(1)
    s.erase(11);

    int key;
    cin >> key;

    if (s.find(key) != s.end())
    {
        cout << key << " is found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    // let us print all the elements of the unordered_Set
    for (auto x : s)
    {
        cout << x << ", ";
    }

    return 0;
}