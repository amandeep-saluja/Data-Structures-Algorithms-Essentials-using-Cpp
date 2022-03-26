#include <bits/stdc++.h>
using namespace std;

int wordBreak(string str, vector<string> &dictionary)
{
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