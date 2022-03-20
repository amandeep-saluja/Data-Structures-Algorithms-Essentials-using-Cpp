#include <iostream>
#include <string>
#include <map>
using namespace std;

void insertWithCount(map<string, int> &v, string s)
{
    map<string, int>::iterator itr = v.find(s);
    if (itr != v.end())
    {
        v.insert({s, itr->second + 1});
    }
    else
    {
        v.insert({s, 1});
    }
}

void printAllPermutations(string &s, int i, int j, map<string, int> &v)
{
    // base case
    if (s[i] == '\0' or i == s.length() - 1)
    {
        insertWithCount(v, s);
        return;
    }

    // recursive case
    printAllPermutations(s, i + 1, i + 1, v);
    for (; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        printAllPermutations(s, i + 1, j, v);
        swap(s[i], s[j]);
    }
}

int main()
{

    string s = "abcdef";
    map<string, int> m;

    printAllPermutations(s, 0, 0, m);

    for (auto &x : m)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}