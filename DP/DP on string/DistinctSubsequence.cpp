#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {

        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        // match
        if (s[i] == t[j])
        {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        }
        // No match
        else
        {
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};
int main()
{   
    string s = "rabbbit", t = "rabbit";
    Solution sol;
    cout << sol.numDistinct(s,t) << endl;
    return 0;
}