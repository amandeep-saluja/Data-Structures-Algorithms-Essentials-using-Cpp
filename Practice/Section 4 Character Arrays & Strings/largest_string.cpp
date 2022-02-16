#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    int n;
    cin >> n;
    cin.get();
    char sentence[1000], largestString[1000];
    int largestLength = 0, len = 0;

    while (n--)
    {
        cin.getline(sentence, 1000);
        len = strlen(sentence);
        if (largestLength < len)
        {
            largestLength = len;
            strcpy(largestString, sentence);
        }
    }

    cout << "Largest string: " << largestString << endl;
    cout << "Largest length: " << largestLength << endl;

    return 0;
}