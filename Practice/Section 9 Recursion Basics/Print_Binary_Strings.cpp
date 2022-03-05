#include <bits/stdc++.h>
using namespace std;

vector<string> s;

void helper(string str, int i, int n)
{
    if (i == n)
    {
        s.push_back(str);
        return;
    }
    else if (str[i - 1] == '1')
    {
        str.push_back('0');
        helper(str, i + 1, n);
    }
    else
    {
        str.push_back('0');
        helper(str, i + 1, n);
        str.pop_back();

        str.push_back('1');
        helper(str, i + 1, n);
    }
}

vector<string> binaryStrings(int n)
{
    // do not modify any default function or parameter you can use helper function if needed
    s.clear();
    string str;
    str.push_back('0');
    helper(str, 1, n);
    str = "1";
    helper(str, 1, n);
    return s;
}

int main()
{

    for (string s : binaryStrings(3))
    {
        cout << s << endl;
    }

    return 0;
}