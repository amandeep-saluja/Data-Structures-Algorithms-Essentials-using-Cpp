#include <bits/stdc++.h>
using namespace std;

vector<int> increasingNumbers(int N)
{
    vector<int> num;

    if(N==0)
        return num;

    num = increasingNumbers(N-1);

    num.push_back(N);

    return num;
}

int main() {
    int n;
    cin >> n;

    for(int x: increasingNumbers(n)) {
        cout << x << " ";
    }

    return 0;
}