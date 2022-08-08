#include <bits/stdc++.h>
using namespace std;

// TC O(N) SC : O(N) for dp + O(N)-> recursive stack space
int f(int ind, vector<int> &arr, vector<int> &dp)
{
    if (ind < 0)
        return 0;
    if (ind == 0)
        return arr[0];

    if (dp[ind] != -1)
        return dp[ind];

    // Pick
    int pick = arr[ind] + f(ind - 2, arr, dp);
    // Not Pick
    int NotPick = 0 + f(ind - 1, arr, dp);

    return dp[ind] = max(pick, NotPick);
}
int main()
{
    vector<int> arr = {2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n + 1, -1);

    // memoization
    cout << f(n - 1, arr, dp) << endl;

    // Tabulation
    // TC O(N) SC: O(N)
    vector<int> dp1(n + 1, 0);
    dp1[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        // Pick
        int pick = INT_MIN;
        if (i > 1)
            pick = arr[i] + dp1[i - 2];
        // Not Pick
        int NotPick = 0 + dp1[i - 1];
        dp1[i] = max(pick, NotPick);
    }
    cout << dp1[n - 1] << endl;

    // Space Optimization
    // TC O(N) and SC O(1)
    int prev = arr[0];
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        // Pick
        int pick = INT_MIN;
        if (i > 1)
            pick = arr[i] + prev2;
        // Not Pick
        int NotPick = 0 + prev;

        int curi = max(pick, NotPick);
        prev2 = prev;
        prev = curi;
    }
    cout << prev << endl;
    return 0;
}