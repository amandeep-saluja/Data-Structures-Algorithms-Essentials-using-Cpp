
#include <iostream>
using namespace std;

int gridSum(int m, int n, int i, int j)
{
    // base case
    if (i == m and j == n)
    {
        return 1;
    }
    else if (i > m or j > n)
        return 0;

    // recursive case

    int ans = gridSum(m, n, i + 1, j) + gridSum(m, n, i, j + 1);

    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;

    int res = gridSum(m - 1, n - 1, 0, 0);
    cout << res << endl;

    return 0;
}
