#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string removeDuplicate(string s)
{
    sort(s.begin(), s.end());
    string s2 = "";

    for (int i = 1; i <= s.length(); i++)
    {
        // s2 += s[i++];
        while (i < s.length() and s[i] == s[i - 1])
        {
            i++;
        }
        s2 += s[i-1];
    }

    return s2;
}

int main()
{
    // string s1 = "geeksforgeeks";
    // string s1 = "bcabc";
    string s1 = "cbacdcbc"; // abbccccd

    string s2 = removeDuplicate(s1);

    cout << s2 << endl;

    return 0;
}