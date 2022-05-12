#include <bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str)
{

    // bool t = false;
    int count = 0;
    stack<char> s;

    for(char c: str) {
        if(c == '(') {
            count = 0;
            s.push(c);
        }
        else if(c == ')') {
            count++;
            s.pop();
        }
    }
    if(count>2)
        return true;
    return false;
}

int main()
{

    string s = "((a+b)+((c+d)))";

    cout << "Duplicate Paranthesis: " << duplicateParentheses(s) << endl;

    return 0;
}