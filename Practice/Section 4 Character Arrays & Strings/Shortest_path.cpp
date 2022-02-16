#include <iostream>
using namespace std;

int main()
{

    char directions[100];
    cin.getline(directions, 100);
    int len = 0, x = 0, y = 0;
    char dir;
    while ((dir = directions[len++]) != '\0')
    {
        if (dir == 'E')
            x++;
        else if (dir == 'W')
            x--;
        else if (dir == 'N')
            y++;
        else if (dir == 'S')
            y--;
    }

    while (y)
    {
        if (y > 0)
        {
            cout << 'N';
            y--;
        }
        else
        {
            cout << 'S';
            y++;
        }
    }

    while (x)
    {
        if (x > 0)
        {
            cout << 'E';
            x--;
        }
        else
        {
            cout << 'W';
            x++;
        }
    }

    return 0;
}