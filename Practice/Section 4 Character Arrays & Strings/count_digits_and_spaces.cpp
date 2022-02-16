#include <iostream>
using namespace std;

int main()
{
    int temp = cin.get();
    int countDigit = 0, countAlphabet = 0, countSpace = 0;

    while (temp != '\n')
    {
        if ((temp >= 'a' and temp <= 'z') or (temp >= 'A' and temp <= 'Z'))
        {
            countAlphabet++;
        }
        else if (temp >= '0' and temp <= '9')
        {
            countDigit++;
        }
        else if (temp == ' ' or temp == '\t')
        {
            countSpace++;
        }
        
        temp = cin.get();
    }

    cout << "Aphabet count: " << countAlphabet << endl;
    cout << "Digit count: " << countDigit << endl;
    cout << "Space count: " << countSpace << endl;

    return 0;
}