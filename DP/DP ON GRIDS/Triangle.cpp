/*
https://leetcode.com/problems/triangle/

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/
#include <bits/stdc++.h>
using namespace std;

// Memoiaztion TC O(n*n) SC(n*n)
int findMinCost(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (x == grid.size() - 1)
    {
        return grid[x][y];
    }
    if (dp[x][y] != -1)
        return dp[x][y];

    int d = grid[x][y] + findMinCost(x + 1, y, grid, dp);
    int dg = grid[x][y] + findMinCost(x + 1, y + 1, grid, dp);

    return dp[x][y] = min(d, dg);
}
int main()
{
    vector<vector<int>> triangle = {
        {1},
        {2, 3},
        {3, 6, 7},
        {8, 5, 6, 10}};

    int n = triangle.size();
    int m = n;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    cout << findMinCost(0, 0, triangle, dp) << endl;

    // Tabulation
    vector<vector<int>> dp1(n, vector<int>(m, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == n - 1)
                dp1[i][j] = triangle[i][j];
            else
            {
                int d = 1e8, dg = 1e8;
                if (i + 1 < n)
                    d = triangle[i][j] + dp1[i + 1][j];
                if (i + 1 < n && j + 1 < i)
                    dg = triangle[i][j] + dp1[i + 1][j + 1];

                dp1[i][j] = min(d, dg);
            }
        }
    }
    cout << dp1[0][0] << endl;
    return 0;
}