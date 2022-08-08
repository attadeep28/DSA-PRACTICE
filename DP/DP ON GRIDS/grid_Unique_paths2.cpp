/*
https://leetcode.com/problems/unique-paths-ii/
An obstacle and space are marked as 1 or 0 respectively in grid.
A path that the robot takes cannot include any square that is an obstacle.
*/
#include <bits/stdc++.h>
using namespace std;
int findpaths(int n, int m, vector<vector<int>> grid, vector<vector<int>> &dp)
{
    if (n == 0 and m == 0)
        return 1;

    if (n < 0 or m < 0 or grid[n][m] == 1)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    int up = findpaths(n - 1, m, grid, dp);
    int left = findpaths(n, m - 1, grid, dp);

    return dp[n][m] = up + left;
}
int main()
{
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << findpaths(n - 1, m - 1, grid, dp) << endl;

    // TABULATION
    // Tabulation TC: O(n*m) SC: O(n*m)
    vector<vector<int>> dp1(n, vector<int>(m, 0));

    dp1[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp1[i][j] = 1;

            else
            {
                int up = 0;
                if (i > 0)
                    up = dp1[i - 1][j];
                int left = 0;
                if (j > 0)
                    left = dp1[i][j - 1];
                dp1[i][j] = up + left;
            }
        }
    }

    cout << dp1[n - 1][m - 1];
    return 0;
}