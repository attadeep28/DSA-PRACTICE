#include <bits/stdc++.h>
using namespace std;
int f(int ind, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        return (w / wt[0]) * val[0];
    }

    if (dp[ind][w] != -1)
        return dp[ind][w];
    // Not Pick
    int notPick = f(ind - 1, w, val, wt, dp);
    // Pick
    int pick = -1e9;
    if (wt[ind] <= w)
    {
        pick = val[ind] + f(ind, w - wt[ind], val, wt, dp);
    }

    return dp[ind][w] = max(pick, notPick);
}
int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int bag = 10;
    int n = wt.size();
    vector<vector<int>> dp1(n, vector<int>(bag + 1, -1));
    cout << f(n - 1, bag, val, wt, dp1) << endl;

    // Tabulation

    vector<vector<int>> dp(n, vector<int>(bag + 1, 0));

    for (int w = 0; w <= bag; w++)
    {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= bag; w++)
        {
            // Not Pick
            int notPick = dp[ind - 1][w];
            // Pick
            int pick = -1e9;
            if (wt[ind] <= w)
            {
                pick = val[ind] + dp[ind][w - wt[ind]];
            }

            dp[ind][w] = max(pick, notPick);
        }
    }
    cout << dp[n - 1][bag] << endl;
    return 0;
}