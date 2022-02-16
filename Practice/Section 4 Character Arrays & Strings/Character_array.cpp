#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'g', 'w', 'q', 't', '\0'};
    char brr[] = "abcdefghij";
    cout << arr << endl;
    cout << brr << endl;

    cout << strlen(arr) << endl;
    cout << sizeof(arr) << endl;

    char crr[100];
    cin >> crr;

    cout << crr << endl;

    return 0;
}