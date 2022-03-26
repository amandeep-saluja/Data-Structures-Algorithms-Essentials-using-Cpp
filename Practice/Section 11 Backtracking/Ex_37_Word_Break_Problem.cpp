#include <bits/stdc++.h>
using namespace std;

bool isFound(string str, vector<string> &dictionary, int i, int j)
{
    int n = str.length() - 1;
    if (i < 0 or j < 0 or i > n or j > n)
    {
        return false;
    }

    for (int k = 0; k < dictionary.size(); k++)
    {
        if (str.substr(i, j - i + 1) == dictionary[k])
        {
            return true;
        }
    }
    return false;
}

int helper(string str, vector<string> &dictionary, int i, int j, string s)
{
    int n = str.length();
    // cout << "n: " << n << " i: " << i << " j: " << j << endl;
    // base case
    if (i == n and j == n)
    {
        cout << s << endl;
        return 1;
    }
    else if (i > n or j > n)
    {
        return 0;
    }

    // recursive case
    int ways = 0;
    if (isFound(str, dictionary, i, j))
    {
        ways += helper(str, dictionary, j + 1, j + 1, s + " " + str.substr(i, j - i + 1));

        // backtrack
        ways += helper(str, dictionary, i, j + 1, s);
        return ways;
    }

    ways += helper(str, dictionary, i, j + 1, s);
    return ways;
}

int wordBreak(string str, vector<string> &dictionary)
{
    string s = "";
    return helper(str, dictionary, 0, 0, s);
}

int main()
{

    vector<string> dictionary = {"i", "like", "sam", "sung", "samsung", "mobile"};
    string str = "ilikesamsungmobile";

    cout << wordBreak(str, dictionary) << endl;

    return 0;
}

/*

Word Break Problem

Given a str which is a valid sentence without any spaces between the words and
a dictionary of valid English words, find all possible number of ways to break
the sentence in individual dictionary words.

Input Format

In the function a string str and a vector of strings representing dictionary is passed

Output Format

Return an integer representing the total no. of ways

Sample Input

dictionary = { i, like, sam, sung, samsung, mobile}

str = "ilikesamsungmobile"

Sample Output

2

Explanation

Following are the 2 possible ways to break the string

i like sam sung mobile
i like samsung mobile

*/