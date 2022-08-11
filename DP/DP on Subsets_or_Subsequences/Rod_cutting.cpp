#include <bits/stdc++.h>
using namespace std;

/*
https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?leftPanelTab=0

given-a-rod-of-length-n-units-the-rod-can-be-cut-into-different-sizes-and-each-size-has-a-cost-associated-with-it-determine-the-maximum-cost-obtained-by-cutting-the-rod-and-selling-its-pieces
*/

int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return N * price[0];
    }
    if (dp[ind][N] != -1)
        return dp[ind][N];

    // Not pick
    int notPick = 0 + f(ind - 1, N, price, dp);
    // Pick
    int rodLen = ind + 1;
    int pick = -1e9;
    if (rodLen <= N)
    {
        pick = price[ind] + f(ind, N - rodLen, price, dp);
    }

    return dp[ind][N] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n)
{
    // Tabulation TC(N * N+1) SC(N*N+1)
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            // Not pick
            int notPick = 0 + dp[ind - 1][N];
            // Pick
            int rodLen = ind + 1;
            int pick = -1e9;
            if (rodLen <= N)
            {
                pick = price[ind] + dp[ind][N - rodLen];
            }

            dp[ind][N] = max(pick, notPick);
        }
    }
    return dp[n - 1][n];
}

int main()
{
    int N = 2;
    int n = 9;
    vector<int> cuts = {5, 6, 1, 4, 2};

    return 0;
}