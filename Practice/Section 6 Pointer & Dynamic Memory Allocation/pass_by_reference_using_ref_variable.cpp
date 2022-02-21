#include <iostream>
using namespace std;

void applyTax(int &money)
{
    float tax = 0.1;
    money = money - money * tax;
}

int main()
{

    int income;
    cin >> income;

    applyTax(income);

    cout << income << endl;

    return 0;
}