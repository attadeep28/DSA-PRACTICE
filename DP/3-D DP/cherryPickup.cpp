#include <bits/stdc++.h>
using namespace std;
/*

https://leetcode.com/problems/cherry-pickup-ii/
You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:


*/
// memoization  TC ( N * M * M * 9)  SC : O(N * M * M ) + O(N)->stack space
int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 or j2 < 0 or j1 >= grid[0].size() or j2 >= grid[0].size())
    {
        return -1e8;
    }
    if (i == grid.size() - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = -1e8;
    for (int y1 = -1; y1 < 2; y1++)
    {
        for (int y2 = -1; y2 < 2; y2++)
        {
            int value = 0;
            if (j1 == j2)
                value = grid[i][j1];
            else
                value = grid[i][j1] + grid[i][j2];

            value += f(i + 1, j1 + y1, j2 + y2, grid, dp);

            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}
int main()
{
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}}; // ans 24

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    cout << f(0, 0, m - 1, grid, dp) << endl;
    return 0;
}