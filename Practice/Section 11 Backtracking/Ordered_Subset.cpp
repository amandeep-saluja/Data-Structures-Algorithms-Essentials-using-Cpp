#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int compare(string a, string b)
{
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    return a < b;
}

void find_subsets(char *input, char *out, int i, int j, vector<string> &v)
{
    if (input[i] == '\0')
    {
        out[j] = '\0';
        v.push_back(out);
        return;
    }

    // with
    out[j] = input[i];
    find_subsets(input, out, i + 1, j + 1, v);
    // without
    find_subsets(input, out, i + 1, j, v);
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    cin >> arr;
    char output[n];
    vector<string> v;

    find_subsets(arr, output, 0, 0, v);
    cout << "Length: " << v.size() << endl;

    sort(v.begin(), v.end(), compare);

    for (string x : v)
    {
        cout << x << " ";
    }

    return 0;
}