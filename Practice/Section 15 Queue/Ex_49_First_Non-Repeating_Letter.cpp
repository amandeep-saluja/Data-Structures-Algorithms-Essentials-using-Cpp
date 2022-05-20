#include <bits/stdc++.h>
#define MAX_CHAR 26
using namespace std;

vector<char> firstnonrepeating(vector<char> str)
{
    // // queue<char> q;
    // vector<char> v;

    // for (int x : str)
    // {
    //     int flag = false;
    //     for (int y : v)
    //     {
    //         if (x == y)
    //         {
    //             flag = true;
    //             break;
    //         }
    //     }
    //     if (flag)
    //     {
    //         v.push_back('0');
    //     }
    //     else
    //     {
    //         v.push_back(x);
    //     }
    // }

    // return v;
    queue<char> q;
    vector<char> v;
    int charCount[MAX_CHAR] = {0};

    for (int i = 0; i < str.size(); i++)
    {

        q.push(str[i]);

        charCount[str[i] - 'a']++;

        while (!q.empty())
        {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                v.push_back(q.front());
                break;
            }
        }

        if (q.empty())
            v.push_back('0');
    }
    return v;
}

int main()
{

    vector<char> str = {'a', 'a', 'b', 'c'};

    for (char c : firstnonrepeating(str))
    {
        cout << c << " ";
    }

    return 0;
}

/*
First Non-Repeating Letter
Given a string, your task is to find first non repeating character at each index otherwise return 0.

Input Format

In the function a vector of character is passed.

NOTE : it will contain only lowercase characters .

Output Format

Return a vector of character.

Sample Input
a a b c

Sample Output
a 0 b b

Explanation

at index 0 : 'a' is the first non repeating character until this index.
at index 1 : as 'a' has come once before and there is no other unique character
until this index therefore '0' will be the answer
at index 2 : 'b' is the first non repeating character until this index.
at index 3 : 'b' is the first non repeating character until this index.
*/