#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    // Memoiazation
    // TC O(N*T) SC: O(N*T) + O(T)
    int f(int ind, int target, vector<int> &a, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target % a[0] == 0)
            {
                return target / a[0];
            }
            else
            {
                return 1e9;
            }
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notpick = 0 + f(ind - 1, target, a, dp);

        int pick = 1e9;
        if (a[ind] <= target)
        {
            pick = 1 + f(ind, target - a[ind], a, dp);
        }

        return dp[ind][target] = min(pick, notpick);
    }

public:
    // Tabulation
    int f1(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int T = 0; T <= amount; T++)
        {
            if (T % coins[0] == 0)
                dp[0][T] = T / coins[0];
            else
                dp[0][T] = 1e8;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notpick = 0 + dp[ind - 1][target];

                int pick = 1e9;
                if (coins[ind] <= target)
                {
                    pick = 1 + dp[ind][target - coins[ind]];
                }

                dp[ind][target] = min(pick, notpick);
            }
        }

        return dp[n - 1][amount];
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int ans;
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        ans = f(n - 1, amount, coins, dp);

        return ans == 1e9 ? -1 : ans;
    }
};
int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << sol.coinChange(coins, amount) << endl;
    cout << sol.f1(coins, amount) << endl;
    return 0;
}