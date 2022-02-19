#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(string s)
{
    int decimal = 0;
    int base = 1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            decimal += base;
        base = base * 2;
    }

    return decimal;
}

int main()
{

    string binary = "111";
    int decimal = binaryToDecimal(binary);

    cout << binary << " binary to decimal string : " << decimal << endl;

    return 0;
}

/*
OLD code

#include
#include
using namespace std;

int binaryToDecimal(string s)
{
   int out=0;
   int base =1;

   for(int i=s.length()-1; i&gt;=0; i--)
   {
       if(s[i]=='1')
            out+=base;
        base = base*2;
   }
   return out;
}


*/

/*

int decimal = 0;

    for (int i = s.length()-1; i >= 0; i--)
    {
        decimal += ((s[i] - '0') * pow(2, i));
    }

    return decimal;

*/
