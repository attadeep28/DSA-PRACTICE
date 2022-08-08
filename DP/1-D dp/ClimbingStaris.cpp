#include <bits/stdc++.h>
using namespace std;
int findAllWays(int ind, vector<int> &dp)
{
    if (ind == 0)
        return 1;
    if (ind < 0)
        return 0;
    // Memoiation
    if (dp[ind] != -1)
        return dp[ind];
    // climb one step
    int oneStep = findAllWays(ind - 1, dp);
    // Climb Two Step
    int TwoStep = findAllWays(ind - 2, dp);

    return dp[ind] = oneStep + TwoStep;
}

int main()
{
    int N = 4;
    vector<int> dp(N + 1, -1);
    cout << findAllWays(N, dp) << " Ways" << endl;
    // Tabulation
    vector<int> dp1(N + 1, 0);
    dp1[0] = 1;
    dp1[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }
    cout << dp1[N];
    return 0;
}