#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int f(int ind, int buy, int cap, vector<int> &prices, int &n, vector<vector<vector<int>>> &dp)
    {
        if (ind == n)
            return 0;
        if (cap <= 0)
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if (buy == 1)
        {
            return dp[ind][buy][cap] = max((-prices[ind] + f(ind + 1, 0, cap, prices, n, dp)), 0 + f(ind + 1, 1, cap, prices, n, dp));
        }
        return dp[ind][buy][cap] = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n, dp), 0 + f(ind + 1, 0, cap, prices, n, dp));
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(0, 1, 2, prices, n, dp);

        // Tabulation
        /*
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy == 1)
                    {
                        dp[ind][buy][cap] = max((-prices[ind] + dp[ind + 1][0][cap]), 0 + dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
        */

        // Space optimization
        vector<vector<int>> ahed(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy == 1)
                    {
                        cur[buy][cap] = max((-prices[ind] + ahed[0][cap]), 0 + ahed[1][cap]);
                    }
                    else
                    {
                        cur[buy][cap] = max(prices[ind] + ahed[1][cap - 1], ahed[0][cap]);
                    }
                }
            }
            ahed = cur;
        }

        return ahed[1][2];
    }
};