#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "abcd", s2 = "abzd";
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = 0;
    // Tabulation
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // match
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    // Space optimization
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // match
            if (s1[i - 1] == s2[j - 1])
            {
                cur[j] = 1 + prev[j - 1];
                ans = max(ans, cur[j]);
            }
            else
                cur[j] = 0;
        }
        prev = cur;
    }
    cout << ans << endl;
    return 0;
}