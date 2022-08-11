#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void longestCommonSubsequence(string s1, string s2)
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

        string s = "";
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                s = s1[i - 1] + s;
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else
                j--;
        }

        cout << s << endl;
    }
};

int main()
{
    Solution sol;
    string text1 = "AGGTAB", text2 = "GXTXAYB";

    sol.longestCommonSubsequence(text1, text2);
    return 0;
}