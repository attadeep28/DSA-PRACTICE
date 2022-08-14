#include <bits/stdc++.h>
using namespace std;
/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).



Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
*/
class Solution
{
private:
    int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
    {
        if (ind >= n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy == 1)
        {
            return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, n, dp),
                                      0 + f(ind + 1, 1, prices, n, dp));
        }

        return dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, prices, n, dp),
                                  0 + f(ind + 1, 0, prices, n, dp));
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1));
        // return f(0,1,prices,n,dp);

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0],
                                       0 + dp[ind + 1][1]);
                }

                else
                {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1],
                                       0 + dp[ind + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};
int main()
{
    return 0;
}