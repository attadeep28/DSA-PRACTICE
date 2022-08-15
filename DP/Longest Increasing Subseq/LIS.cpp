#include <bits/stdc++.h>
using namespace std;
int LIS(int ind, int prev, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    // Not Take
    int notTake = 0 + LIS(ind + 1, prev, arr, n, dp);
    // Take
    int take = 0;
    if (arr[ind] > arr[prev] or prev == -1)
    {
        take = 1 + LIS(ind + 1, ind, arr, n, dp);
    }

    return dp[ind][prev + 1] = max(take, notTake);
}
int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = nums.size();
    vector<vector<int>> dp1(n, vector<int>(n + 1, -1));
    cout << LIS(0, -1, nums, n, dp1) << endl;

    // TAbulation TC(n*n) SC(n*n)
    vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int pre = ind - 1; pre >= -1; pre--)
        {

            int len = 0 + dp2[ind + 1][pre + 1];

            if (pre == -1 or nums[ind] > nums[pre])
            {
                len = max(len, 1 + dp2[ind + 1][ind + 1]);
            }

            dp2[ind][pre + 1] = len;
        }
    }

    cout << dp2[0][0] << endl;

    // Optimized TC(n*n) SC(N)
    vector<int> dp(n + 1, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[prev] < nums[i])
            {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }

    cout << maxi << endl;

    return 0;
}