/*
https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998
Max path sum from any cell in the first row to any cell in the last row
*/
#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (j < 0 or j >= mat[0].size())
        return -1e9;

    if (i == 0)
        return mat[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = mat[i][j] + f(i - 1, j, mat, dp);
    int rd = mat[i][j] + f(i - 1, j + 1, mat, dp);
    int ld = mat[i][j] + f(i - 1, j - 1, mat, dp);

    return dp[i][j] = max(up, max(rd, ld));
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}}; // 105
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MIN;
    // MEMOIZATION
    vector<vector<int>> dp1(n, vector<int>(m, -1));
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, f(n - 1, i, matrix, dp1));
    }

    cout << ans << endl;

    // TABULATION
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initializing first row - base condition
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int up = matrix[i][j] + dp[i - 1][j];

            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0)
                leftDiagonal += dp[i - 1][j - 1];
            else
                leftDiagonal += -1e9;

            int rightDiagonal = matrix[i][j];
            if (j + 1 < m)
                rightDiagonal += dp[i - 1][j + 1];
            else
                rightDiagonal += -1e9;

            dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    cout << maxi << endl;
    return 0;
}