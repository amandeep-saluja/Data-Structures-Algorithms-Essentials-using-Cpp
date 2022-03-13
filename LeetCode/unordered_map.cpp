#include <iostream>
#include <unordered_map>
using namespace std;

void printMap1(unordered_map<int, int> &m)
{
    if (m.size() == 0)
    {
        cout << "No element found." << endl;
        return;
    }

    unordered_map<int, int>::iterator it;

    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

void printMap2(unordered_map<int, int> &m)
{
    if (m.size() == 0)
    {
        cout << "No element found." << endl;
        return;
    }

    for (auto &p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int square(int x)
{
    return x * x;
}

int main()
{
    unordered_map<int, int> squares;

    for (int i = 1; i < 10; i++)
    {
        squares.insert({i, square(i)}); // O[1]
    }

    // printMap1(squares);
    // printMap2(squares);

    // unordered_map<int, int>::iterator it = squares.find(3);

    // // O[1]
    // if (it != squares.end())
    // {
    //     cout << it->first << " " << it->second << endl;
    //     squares.erase(it);
    // }
    // else
    // {
    //     cout << "Not found" << endl;
    // }
    // squares.clear();

    printMap2(squares);

    return 0;
}