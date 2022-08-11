#include <bits/stdc++.h>
using namespace std;
int countSubsets(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (ind == 0)
        return arr[ind] == sum;

    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    int NotPick = countSubsets(ind - 1, sum, arr, dp);
    int pick = 0;

    if (arr[ind] <= sum)
        pick = countSubsets(ind - 1, sum - arr[ind], arr, dp);

    return dp[ind][sum] = pick + NotPick;
}
int main()
{
    vector<int> arr = {1, 2, 3};
    int sum = 3;
    int k = sum;
    int n = arr.size();
    vector<vector<int>> dp1(n, vector<int>(sum + 1, -1));
    cout << countSubsets(n - 1, sum, arr, dp1) << endl;

    // Tabulation
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {

            int notTaken = dp[ind - 1][target];

            int taken = 0;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];

            dp[ind][target] = notTaken + taken;
        }
    }
    cout << dp[n - 1][k] << endl;

    return 0;
}