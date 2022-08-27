#include <bits/stdc++.h>
using namespace std;

// Top down approach

int minNoOfCoins(vector<int> coins, int amount)
{
}

// Bottom up approach
int minCoinChange(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    int t = coins.size();

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;
        for (int c : coins)
        {
            if (i - c >= 0 and dp[i - c] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main()
{

    // vector<int> coins = {1, 3, 7, 10};
    // int amount = 15;
    // vector<int> coins = {2};
    // int amount = 3;
    // vector<int> coins = {1};
    // int amount = 0;
    vector<int> coins = {2};
    int amount = 4;

    cout << minCoinChange(coins, amount) << endl;

    return 0;
}

/*

int minCoinChange(vector<int> coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    int t = coins.size();

    for (int i = 1; i <= amount; i++)
    {
        int minCoins = amount;
        for (int j = 0; j < t; j++)
        {
            int curr = i - coins[j];
            if (curr < 0)
                break;

            curr = dp[curr];
            minCoins = min(curr, minCoins);
        }
        if (minCoins == amount)
            return -1;
        dp[i] = minCoins + 1;
    }

    return dp[amount];
}

*/