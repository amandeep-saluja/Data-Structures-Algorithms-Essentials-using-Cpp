#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    char a[1000] = "apple";
    char b[1000];

    cout << strlen(a) << endl;

    strcpy(b, a);
    cout << b << endl;

    cout << strcmp(a, b) << endl;

    char web[] = "www.";
    char domain[] = "google.com";

    strcpy(b, strcat(web, domain));
    cout << strcat(web, domain) << endl;
    cout << strcmp(b, a) << endl;

    return 0;
}