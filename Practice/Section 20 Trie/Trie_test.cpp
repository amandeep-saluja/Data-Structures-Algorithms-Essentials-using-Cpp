#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{

    string words[] = {"hello", "he", "apple", "aple", "news"};
    Trie t;

    for (string s : words)
    {
        t.insert(s);
    }

    string key;
    cin >> key;

    cout << t.search(key) << endl;

    return 0;
}