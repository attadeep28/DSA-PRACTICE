#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &arr, int k, vector<int> &dp)
{
    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];
    int jump = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (ind - i >= 0)
        {
            int kJump = f(ind - i, arr, k, dp) + abs(arr[ind] - arr[ind - i]);
            jump = min(jump, kJump);
        }
    }
    return dp[ind] = jump;
}
int main()
{
    int n;
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    n = arr.size();
    int k = 2;
    vector<int> dp(n + 1, -1);
    // Memoization
    cout << f(n - 1, arr, k, dp) << endl;

    // Tabulation
    vector<int> dp1(n + 1, -1);

    dp1[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int jump = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int kJump = dp1[i - j] + abs(arr[i] - arr[i - j]);
                jump = min(jump, kJump);
            }
        }
        dp1[i] = jump;
    }
    cout << dp1[n - 1] << endl;
    return 0;
}