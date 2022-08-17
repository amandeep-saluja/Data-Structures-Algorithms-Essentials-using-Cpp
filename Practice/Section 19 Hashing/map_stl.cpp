#include <iostream>
#include <map>

using namespace std;

int main()
{

    map<string, int> menu;

    // Insert key value pairs inside the hashtable O[logN] operation
    menu["Maggie"] = 15;
    menu["colddrink"] = 20;
    menu["dosa"] = 99;
    menu["indianplatter"] = 399;
    menu["pizza"] = 499;

    // updation O[logN]
    menu["dosa"] = (1 + 0.1) * menu["dosa"];

    // Deletion O[logN]
    menu.erase("dosa");

    // Search O[logN]
    string item;
    cin >> item;

    cout << menu["dosa"] << endl;

    if (menu.count(item) == 0)
    {
        cout << item << " is not available" << endl;
    }
    else
    {
        cout << item << " is available, and its cost is " << menu[item] << endl;
    }

    for (pair<string, int> item : menu)
    {
        cout << item.first << " - " << item.second << endl;
    }

    return 0;
}