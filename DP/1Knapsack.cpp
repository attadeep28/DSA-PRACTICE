#include <bits/stdc++.h>
using namespace std;
/*  https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542
    n = 3   bagCapacity: 8
    wt:  3  4  5
    val: 30 50 60
*/

// Memoiation TC : O(N*W) SC: O(N*W) + O(N)
int f(int ind, vector<int> &wt, vector<int> &val, int w, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[ind] <= w)
            return val[ind];
        return 0;
    }

    if (dp[ind][w] != -1)
        return dp[ind][w];

    // Not Pick
    int notPick = f(ind - 1, wt, val, w, dp);
    // Pick
    int pick = -1e8;
    if (wt[ind] <= w)
    {
        pick = val[ind] + f(ind - 1, wt, val, w - wt[ind], dp);
    }

    return dp[ind][w] = max(pick, notPick);
}
int main()
{
    vector<int> wt = {3, 4, 5};
    vector<int> val = {30, 50, 60};
    int n = wt.size();
    int bagCapacity = 8;

    vector<vector<int>> dp1(n, vector<int>(bagCapacity + 1, -1));
    cout << f(n - 1, wt, val, bagCapacity, dp1) << endl;

    // TABULATION TC : O(N*W) SC: O(N*W)
    vector<vector<int>> dp(n, vector<int>(bagCapacity + 1, 0));

    for (int W = wt[0]; W <= bagCapacity; W++)
        dp[0][W] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= bagCapacity; w++)
        {
            // Not Pick
            int notPick = dp[ind - 1][w];
            // Pick
            int pick = -1e8;
            if (wt[ind] <= w)
            {
                pick = val[ind] + dp[ind - 1][w - wt[ind]];
            }

            dp[ind][w] = max(pick, notPick);
        }
    }

    cout << dp[n - 1][bagCapacity] << endl;

    // Space optimization
    vector<int> prev(bagCapacity + 1, 0), cur(bagCapacity + 1, 0);

    for (int W = wt[0]; W <= bagCapacity; W++)
        prev[W] = val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= bagCapacity; w++)
        {
            // Not Pick
            int notPick = prev[w];
            // Pick
            int pick = -1e8;
            if (wt[ind] <= w)
            {
                pick = val[ind] + prev[w - wt[ind]];
            }

            cur[w] = max(pick, notPick);
        }
        prev = cur;
    }

    cout << prev[bagCapacity] << endl;

    return 0;
}