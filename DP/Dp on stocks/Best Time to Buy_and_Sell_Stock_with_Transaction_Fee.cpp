#include <bits/stdc++.h>
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
*/
using namespace std;
class Solution
{
private:
    int f(int ind, int buy, vector<int> &prices, int n, int &fee, vector<vector<int>> &dp)
    {
        if (ind == n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 1)
        {
            return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, n, fee, dp), 0 + f(ind + 1, 1, prices, n, fee, dp));
        }

        return dp[ind][buy] = max(prices[ind] - fee + f(ind + 1, 1, prices, n, fee, dp),
                                  0 + f(ind + 1, 0, prices, n, fee, dp));
    }

public:
    int maxProfit(vector<int> &price, int fee)
    {
        int n = price.size();
        // vector<vector<int>> dp(n, vector<int>(2,-1));
        // return f(0, 1, prices, n, fee, dp);
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
                    profit = max(price[ind] - fee + next[1], next[0]);
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