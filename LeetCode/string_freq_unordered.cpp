#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void printMap(unordered_map<string, int> &m)
{
    for (auto &p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}

void printFreq(unordered_map<string, int> &m, string k)
{
    auto it = m.find(k);
    if (it != m.end())
    {
        cout << "Frequency: " << it->second << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
}

int main()
{

    unordered_map<string, int> m;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string key;
        cin >> key;
        auto it = m.find(key);
        if (it != m.end())
        {
            m.insert({key, it->second++});
        }
        else
        {
            m.insert({key, 1});
        }
    }

    printMap(m);

    printFreq(m, "abc");

    return 0;
}