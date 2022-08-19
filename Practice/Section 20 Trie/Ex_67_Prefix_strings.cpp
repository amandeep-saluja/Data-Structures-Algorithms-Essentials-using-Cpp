#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;

vector<string> findPrefixStrings(vector<string> words, string prefix)
{
    // your code goes here
}

int main()
{

    vector<string> words = {"abc", "abd", "acde", "abe", "aeb", "abba"};

    string small = "ab";

    for (auto s : findPrefixStrings(words, small))
    {
        cout << s << ", ";
    }
}