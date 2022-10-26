#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Memoiation TC O(N*M) SC: O(N*M) + O(N+M)
    int f(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 or ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        // match
        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
        // not match
        return dp[ind1][ind2] = max(f(ind1 - 1, ind2, s1, s2, dp), f(ind1, ind2 - 1, s1, s2, dp));
    }

public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Tabulation TC O(N*M) SC: O(N*M)
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            { 

                // match
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    // not match
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Space Optimization
        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                // match
                if (s1[i - 1] == s2[j - 1])
                    cur[j] = 1 + prev[j - 1];
                else
                    // not match
                    cur[j] = max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};

int main()
{
    Solution sol;
    string text1 = "abcde", text2 = "ace";
    cout << sol.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}