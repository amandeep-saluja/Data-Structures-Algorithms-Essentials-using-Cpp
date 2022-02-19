#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
// Optimized solution
    int n = chars.size();
    int len = 0;

    for (int i = 0, j = 0; j < n;)
    {
        i = j;

        while (j < n and chars[i] == chars[j])
        {
            j++;
        }
        chars[len++] = chars[i];
        int count = j - i;

        if (count > 1)
        {
            for (char c : to_string(count))
            {
                chars[len++] = c;
            }
            continue;
        }
        i++;
    }

    return len;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    // vector<char> chars = {'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'c', 'c', 'c'};
    // vector<char> chars = {'a', 'b', 'c'};
    // vector<char> chars = {'a'};

    int len = compress(chars);

    cout << "Length :" << len << endl;

    for (int i = 0; i < len; i++)
    {
        cout << chars[i] << " ";
    }

    return 0;
}

/*
OLD solution 1:


int count = 1, j = 0;
    char previousChar;
    for (int i = 0; i < chars.size(); i++)
    {
        if (i == 0)
        {
            previousChar = chars[i];
            count = 1;
            j++;
            continue;
        }
        if (previousChar == chars[i])
        {
            count++;
        }
        else
        {
            if(count>1) {
                for (char c : to_string(count))
                {
                    chars[j++] = c;
                }
            }
            previousChar = chars[i];
            count = 1;
            chars[j++] = previousChar;
        }
    }

    if (count > 1)
    {
        for (char c : to_string(count))
        {
            chars[j++] = c;
        }
    }

    return j;

*/

/*
Solution 2:

int n = chars.size();
    int len = 0;

    for (int i = 0, j = 0, k = 0; j < n; k++)
    {
        i = j;

        while (chars[i] == chars[j] && j < n)
        {
            j++;
        }

        int count = j - i;
        if (count > 1)
        {
            len++;
            for (char c : to_string(count))
            {
                // cout << "here " << c << " " << chars[k] << endl;
                chars[k] = chars[i];
                chars[++k] = c;
                len++;
                i++;
            }
            continue;
        }
        len++;
        i++;
        // cout << "loop" << endl;
    }

    return len;
*/

/*
Solution: 3

int i = 0, n = chars.size();
    int newLen = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && chars[j] == chars[i])
        {
            j++;
        }
        chars[newLen++] = chars[i];

        if (j - i > 1)
        {
            for (char c : to_string(j - i))
            {
                chars[newLen++] = c;
            }
        }
        i = j;
    }
    return newLen;
*/