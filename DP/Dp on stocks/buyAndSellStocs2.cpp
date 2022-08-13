/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int f(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;
        if (buy)
        {
            profit = max(-price[ind] + f(ind + 1, 0, price, n, dp), 0 + f(ind + 1, 1, price, n, dp));
        }
        else
        {
            profit = max(price[ind] + f(ind + 1, 1, price, n, dp), f(ind + 1, 0, price, n, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int> &price)
    {
        int n = price.size();

        // Tabulation
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-price[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                else
                {
                    profit = max(price[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];

        // Space optimization
        vector<int> next(2, 0), cur(2, 0);
        next[0] = next[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-price[ind] + next[0], next[1]);
                }
                else
                {
                    profit = max(price[ind] + next[1], next[0]);
                }
                cur[buy] = profit;
            }
            next = cur;
        }

        return next[1];
    }
};
int main()
{
    return 0;
}