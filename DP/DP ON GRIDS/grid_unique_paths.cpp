#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/unique-paths/
*/

// Memoization TC O(n*m) SC :O(n-1+m-1)--> recursion path length + O(n*m)-> dp array

int findPaths(int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 and m == 0)
        return 1;
    if (n < 0 or m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int up = findPaths(n - 1, m, dp);
    int left = findPaths(n, m - 1, dp);

    return dp[n][m] = up + left;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << findPaths(n - 1, m - 1, dp) << endl;

    // Tabulation TC: O(n*m) SC: O(n*m)
    vector<vector<int>> dp1(n, vector<int>(m, 0));

    dp1[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                int left = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }

    cout << dp[n - 1][m - 1];
    return 0;
}