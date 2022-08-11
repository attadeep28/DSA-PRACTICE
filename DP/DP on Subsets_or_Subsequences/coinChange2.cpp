#include <bits/stdc++.h>
using namespace std;
int countWays(int ind, int target, vector<int> &a)
{
    if (target == 0)
        return 1;
    if (ind == 0)
    {
        return target % a[0] == 0;
    }

    // Not Pick
    int notPick = countWays(ind - 1, target, a);
    // Pick
    int pick = 0;
    if (a[ind] <= target)
    {
        pick = countWays(ind, target - a[ind], a);
    }

    return pick + notPick;
}
int main()
{
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int T = 0; T <= amount; T++)
    {
        dp[0][T] = (T % coins[0] == 0);
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= amount; T++)
        {
            // not pick
            int notPick = dp[ind - 1][T];
            // pick

            int pick = 0;
            if (coins[ind] <= T)
            {
                pick = dp[ind][T - coins[ind]];
            }

            dp[ind][T] = pick + notPick;
        }
    }

    cout<<dp[n-1][amount]<<endl;
    return 0;
}