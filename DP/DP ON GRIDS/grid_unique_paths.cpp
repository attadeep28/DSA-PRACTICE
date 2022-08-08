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
    cout << findPaths(n - 1, m - 1, dp);
    return 0;
}