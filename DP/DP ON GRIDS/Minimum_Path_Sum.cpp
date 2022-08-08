/*
https://leetcode.com/problems/minimum-path-sum/
*/
#include <bits/stdc++.h>
using namespace std;
int findMiniPathSum(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (n == 0 and m == 0)
    {
        return grid[0][0];
    }
    if (n < 0 or m < 0)
        return 1e9;

    if (dp[n][m] != -1)
        return dp[n][m];
    int up = grid[n][m] + findMiniPathSum(n - 1, m, grid, dp);
    int left = grid[n][m] + findMiniPathSum(n, m - 1, grid, dp);

    return dp[n][m] = min(up, left);
}
int main()
{
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << findMiniPathSum(n - 1, m - 1, grid, dp) << endl;

    vector<vector<int>> dp1(n, vector<int>(m, 0));
    dp1[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 and j == 0)
                dp1[i][j] = grid[i][j];
            else
            {
                int up = 1e9, left = 1e9;
                if (i > 0)
                    up = grid[i][j] + dp1[i - 1][j];
                if (j > 0)
                    left = grid[i][j] + dp1[i][j - 1];

                dp1[i][j] = min(up, left);
            }
        }
    }
    cout << dp1[n - 1][m - 1] << endl;
    return 0;
}