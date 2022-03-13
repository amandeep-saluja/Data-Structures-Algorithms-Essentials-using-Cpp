#include <iostream>
#include <map>
#include <string>
using namespace std;

void printMap(map<string, int> &m)
{
    for (auto &p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{

    map<string, int> m;
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

    return 0;
}