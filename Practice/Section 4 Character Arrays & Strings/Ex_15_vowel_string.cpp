#include <iostream>
#include <string>
using namespace std;

string findVowels(string s)
{
    string vowels = "";

    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowels += s[i];
            break;
        default:
            break;
        }
        // cout << s[0] << "    " << s << endl;
    }

    return vowels;
}

int main()
{

    string s = "aeoibsddaeioudb";

    string vowels = findVowels(s);

    cout << vowels << endl;

    return 0;
}