#include <iostream>
using namespace std;

int printSumOfNum(int n) {
    if(n==1)
        return 1;

    return n + printSumOfNum(n-1);
}

int main()
{

    int n;
    cin >> n;

    cout << printSumOfNum(n) << endl;

    return 0;
}