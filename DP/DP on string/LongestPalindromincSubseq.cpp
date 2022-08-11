#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1 = "cbbd", s2;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // match
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    // Space optimization
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // match
            if (s1[i - 1] == s2[j - 1])
            {
                cur[j] = 1 + prev[j - 1];
            }
            else
            {
                cur[j] = max(prev[j], cur[j - 1]);
            }
        }
        prev = cur;
    }
    cout << prev[m] << endl;
    return 0;
}