#include <iostream>
#include <string>
using namespace std;

string compress(string s)
{
    int n = s.length();
    string cs = "";

    for (int i = 0, j = 0; i < n;)
    {
        while (j < n and s[i] == s[j])
        {
            j++;
        }
        cs += s[i];
        
        if (j - i > 1)
        {
            cs += to_string(j - i);
        }
        i = j;
    }

    return cs;
}

int main()
{

    // string s = "aabbbcccccccc";
    string s = "abccccd";

    string compressedString = compress(s);

    cout << "Length: " << compressedString.length() << endl;

    cout << "Compressed String: " << compressedString << endl;

    return 0;
}