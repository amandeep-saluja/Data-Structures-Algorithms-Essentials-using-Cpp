#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char sentence[100];

    char temp = cin.get();
    int l = 0;
    while(temp!='\n') {
        sentence[l++] = temp;
        temp = cin.get();
    }

    cout << sentence<<endl;
    cout << strlen(sentence) << endl;

    return 0;
}