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
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahed(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
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

        return ahed[1][k];
    }
};