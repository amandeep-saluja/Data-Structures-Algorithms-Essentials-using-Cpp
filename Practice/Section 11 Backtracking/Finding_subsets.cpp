#include <iostream>
using namespace std;

void find_subsets(char *input, char *out, int i, int j)
{
    if (input[i] == '\0')
    {
        out[j] = '\0';
        cout << out << " ";
        return;
    }

    // with
    out[j] = input[i];
    find_subsets(input, out, i + 1, j + 1);
    // without
    find_subsets(input, out, i + 1, j);
}

int main()
{
    int n;
    cin >> n;
    char arr[n];
    cin >> arr;
    char output[n];

    find_subsets(arr, output, 0, 0);

    return 0;
}