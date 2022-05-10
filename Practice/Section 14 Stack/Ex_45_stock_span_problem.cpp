#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpanner(vector<int> &stockPrices)
{
    stack<int> s;
    vector<int> span(stockPrices.size(), 0);

    span[0] = 1;
    s.push(0);

    for (int i = 1; i < stockPrices.size(); i++)
    {
        int curr_price = stockPrices[i];
        while (!s.empty() and stockPrices[s.top()] <= curr_price)
        {
            s.pop();
        }
        if (!s.empty())
        {
            int prev_highest = s.top();
            span[i] = i - prev_highest;
        }
        else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }

    return span;
}

int main()
{

    vector<int> stocks = {100, 80, 60, 70, 60, 75, 85};

    vector<int> span = stockSpanner(stocks);

    for (int x : span)
    {
        cout << x << " ";
    }

    return 0;
}

/*
Stock Span Problem

Write a class StockSpanner which collects daily price quotes for some stock,
and returns the span of that stock's price for the current day.
The span of the stock's price today is defined as the maximum number of
consecutive days (starting from today and going backwards) for which the price
of the stock was less than or equal to today's price.
For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85],
then the stock spans would be [1, 1, 1, 2, 1, 4, 6].

Input Format
In the function an integer vector is passed representing daily prices.

Output Format
Return an integer vector representing the span of that stock's price
*/

/*
Code 1:
vector<int> stockSpanner(vector<int> &stocks)
{
    vector<int> span;

    for (int i = 0; i < stocks.size(); i++)
    {
        int count = 1;
        bool flag = false;
        for (int j = i - 1; j >= 0; j--)
        {
            if (stocks[j] <= stocks[i])
            {
                count++;
                flag = true;
            }
            else
            {
                break;
            }
        }
        span.push_back(count);
    }

    return span;
}
*/

/*
Code: 2
vector<int> stockSpanner(vector<int> &stocks)
{
    vector<int> span;

    for (int i = 0; i < stocks.size(); i++)
    {
        int j = i;
        while (j >= 0)
        {
            if (stocks[j] > stocks[i])
            {
                break;
            }
            else
            {
                j--;
            }
        }
        span.push_back(i-j);
    }

    return span;
}

*/